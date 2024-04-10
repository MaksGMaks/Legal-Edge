#include "DatabaseManager.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>

#include "../Endpoints.hpp"

DatabaseManager::DatabaseManager(const std::string &path_to_db, const std::string &path_to_sql_script) noexcept : m_path_to_db{path_to_db},
                                                                                                                  m_configure_path{path_to_sql_script}
{
    std::cout << "DatabaseManager::DatabaseManager" << std::endl;
}

DatabaseManager::~DatabaseManager()
{
    std::cout << "DatabaseManager::~DatabaseManager" << std::endl;
    sqlite3_close(db);
}

int executeSql(sqlite3 *db, const std::string &sql)
{
    char *errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error in exequteSql: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return 1;
    }

    std::cout << "SQL-done" << std::endl;
    return 0;
}

void DatabaseManager::start()
{
    int rc = sqlite3_open(m_path_to_db.c_str(), &db);
    if (rc)
    {
        std::cout << "Invalid open database - " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "db was created correctly" << std::endl;
    }
    auto filename = m_configure_path.c_str();
    if (!std::filesystem::exists(filename))
    {
        std::cout << "filepath to sql script does not exist" << std::endl;
    }

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "invalid to open sql script - " << filename << std::endl;
    }

    std::string line;
    std::stringstream sqlBuilder;
    while (std::getline(file, line))
    {
        if (!line.empty() && line != "\n" && line != "\r")
        {
            sqlBuilder << line;
            if (line.back() == ';')
            {
                std::string sql = sqlBuilder.str();
                if (executeSql(db, sql) != 0)
                {
                    std::cerr << "ERROR IN THE HEART OF WHILE - " << filename << std::endl;
                }
                sqlBuilder.str("");
                sqlBuilder.clear();
            }
        }
    }
}

std::vector<std::list<std::string>> DatabaseManager::executeQuery(const std::string &query, const std::vector<std::string> &params)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    sqlite3_stmt *stmt;

    // Подготавливаем SQL запрос
    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "not при подготовке SQL запроса: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return {};
    }

    // Привязываем параметры к запросу
    for (int i = 0; i < params.size(); ++i)
    {
        rc = sqlite3_bind_text(stmt, i + 1, params[i].c_str(), -1, SQLITE_STATIC);
        if (rc != SQLITE_OK)
        {
            std::cerr << "ERRoR Ошибка при привязке параметра: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return {};
        }
    }

    // Создаем двумерный вектор для хранения результатов
    std::vector<std::list<std::string>> result;

    // Выполняем запрос
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        // Создаем временный вектор для хранения данных текущей строки результата
        std::list<std::string> row;

        // Получаем и сохраняем значения столбцов текущей строки
        for (int i = 0; i < sqlite3_column_count(stmt); ++i)
        {
            const unsigned char *value = sqlite3_column_text(stmt, i);
            row.push_back(std::string(reinterpret_cast<const char *>(value)));
        }

        // Добавляем текущую строку в результат
        result.push_back(row);
    }

    // Проверяем наличие ошибок при выполнении запроса
    if (rc != SQLITE_DONE)
    {
        std::cerr << "Ошибка при выполнении запроса: " << sqlite3_errmsg(db) << std::endl;
    }

    // Освобождаем ресурсы
    sqlite3_finalize(stmt);
    return result;
}

std::vector<std::list<std::string>> DatabaseManager::executeQuery(const std::string &query)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    sqlite3_stmt *stmt;
    std::vector<std::list<std::string>> result;

    // Подготавливаем SQL запрос
    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Ошибка при подготовке SQL запроса: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return {};
    }
    // Выполняем запрос
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        // Создаем временный вектор для хранения данных текущей строки результата
        std::list<std::string> row;

        // Получаем и сохраняем значения столбцов текущей строки
        for (int i = 0; i < sqlite3_column_count(stmt); ++i)
        {
            const unsigned char *value = sqlite3_column_text(stmt, i);
            row.push_back(std::string(reinterpret_cast<const char *>(value)));
        }

        // Добавляем текущую строку в результат
        result.push_back(row);
    }

    // Проверяем наличие ошибок при выполнении запроса
    if (rc != SQLITE_DONE)
    {
        std::cerr << "Ошибка при выполнении запроса: " << sqlite3_errmsg(db) << std::endl;
    }

    // Освобождаем ресурсы
    sqlite3_finalize(stmt);
    return result;
}
// dbResponse DatabaseManager::executeQuery(const std::string &query, const std::vector<std::string> &params)
// {
//     dbResponse response;
//     sqlite3_stmt *stmt;
//     int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
//     if (rc != SQLITE_OK)
//     {
//         std::cerr << "Ошибка подготовки запроса: " << sqlite3_errmsg(db) << std::endl;
//         response.dataset[Keys::_ERROR].push_back("Error - " + std::string(sqlite3_errmsg(db)));
//         response.contains = false;
//         response.SQL_OK = 1;
//         return response;
//     }

//     for (size_t i = 0; i < params.size(); ++i)
//     {
//         rc = sqlite3_bind_text(stmt, static_cast<int>(i + 1), params[i].c_str(), -1, SQLITE_TRANSIENT);
//         if (rc != SQLITE_OK)
//         {
//             std::cerr << "Ошибка установки параметра: " << sqlite3_errmsg(db) << std::endl;
//             sqlite3_finalize(stmt);
//             response.dataset[Keys::_ERROR].push_back("Error - " + std::string(sqlite3_errmsg(db)));
//             response.contains = false;
//             response.SQL_OK = 1;
//             return response;
//         }
//     }

//     rc = sqlite3_step(stmt);
//     if (rc != SQLITE_DONE)
//     {
//         std::cerr << "Ошибка выполнения запроса: " << sqlite3_errmsg(db) << std::endl;
//         sqlite3_finalize(stmt);
//         response.dataset[Keys::_ERROR].push_back("Error - " + std::string(sqlite3_errmsg(db)));
//         response.contains = false;
//         response.SQL_OK = 1;
//         return response;
//     }

//     // Получение результата запроса
//     int count = sqlite3_column_int(stmt, 0);
//     if (count > 0)
//     {
//         response.contains = true;
//     }
//     sqlite3_finalize(stmt);
//     response.SQL_OK = 0;
//     return response;
// }

// int callback(void *NotUsed, int argc, char **argv, char **azColName)
// {
//     for (int i = 0; i < argc; i++)
//     {
//         std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
//     }
//     return 0;
// }

// void DatabaseManager::insertTest()
// {
//     const char *sql = "INSERT INTO users(ID, USERNAME, PASSWORD) VALUES(1, 'admin', 'admin')";

//     char *zErrMsg = 0;

//     int rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
//     if (rc != SQLITE_OK)
//     {
//         std::cerr << "Ошибка SQL: " << zErrMsg << std::endl;
//         sqlite3_free(zErrMsg);
//     }
//     else
//     {
//         std::cout << "Данные успешно добавлены в таблицу." << std::endl;
//     }
// }

// void DatabaseManager::selectTest()
// {
//     std::cout << "select test" << std::endl;
//     const char *sql = "SELECT * FROM users";

//     // auto callback = [](void *data, int argc, char **argv, char **azColName) -> int
//     // {
//     //     std::cout << "into callback" << std::endl;
//     //     int i;
//     //     for (i = 0; i < argc; i++)
//     //     {
//     //         std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
//     //     }
//     //     std::cout << std::endl;
//     //     return 0;
//     // };
//     char *zErrMsg = 0;

//     int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
//     if (rc != SQLITE_OK)
//     {
//         std::cerr << "Ошибка SQL: " << zErrMsg << std::endl;
//         sqlite3_free(zErrMsg);
//     }
//     std::cout << "after select test" << std::endl;
// }