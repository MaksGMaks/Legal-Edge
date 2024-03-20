#include "DatabaseManager.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>

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
                    std::cerr << "Ошибка выполнения SQL-скрипта из файла: " << filename << std::endl;
                }
                sqlBuilder.str("");
                sqlBuilder.clear();
            }
        }
    }
}
int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    return 0;
}

void DatabaseManager::insertTest()
{
    const char *sql = "INSERT INTO users(ID, USERNAME, PASSWORD) VALUES(1, 'admin', 'admin')";

    // Выполняем SQL-запрос
    char *zErrMsg = 0;

    int rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Ошибка SQL: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "Данные успешно добавлены в таблицу." << std::endl;
    }
}

void DatabaseManager::selectTest()
{
    std::cout << "select test" << std::endl;
    const char *sql = "SELECT * FROM users";

    // Функция обратного вызова для обработки результатов запроса
    // auto callback = [](void *data, int argc, char **argv, char **azColName) -> int
    // {
    //     std::cout << "into callback" << std::endl;
    //     int i;
    //     for (i = 0; i < argc; i++)
    //     {
    //         std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    //     }
    //     std::cout << std::endl;
    //     return 0;
    // };
    char *zErrMsg = 0;

    // Выполняем SELECT-запрос
    int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Ошибка SQL: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    std::cout << "after select test" << std::endl;
}