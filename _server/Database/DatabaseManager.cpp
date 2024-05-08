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

std::vector<std::vector<std::string>> DatabaseManager::executeQuery(const std::string &query, const std::vector<std::string> &params)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "not при подготовке SQL запроса: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return {};
    }

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

    std::vector<std::vector<std::string>> result;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        std::vector<std::string> row;

        for (int i = 0; i < sqlite3_column_count(stmt); ++i)
        {
            const unsigned char *value = sqlite3_column_text(stmt, i);
            row.push_back(std::string(reinterpret_cast<const char *>(value)));
        }

        result.push_back(row);
    }

    if (rc != SQLITE_DONE)
    {
        std::cerr << "Ошибка при выполнении запроса: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    auto r = processor(result);
    return r;
}

std::vector<std::vector<std::string>> DatabaseManager::executeQuery(const std::string &query)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    sqlite3_stmt *stmt;
    std::vector<std::vector<std::string>> result;

    int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Ошибка при подготовке SQL запроса: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return {};
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        std::vector<std::string> row;

        for (int i = 0; i < sqlite3_column_count(stmt); ++i)
        {
            const unsigned char *value = sqlite3_column_text(stmt, i);
            row.push_back(std::string(reinterpret_cast<const char *>(value)));
        }

        result.push_back(row);
    }

    if (rc != SQLITE_DONE)
    {
        std::cerr << "Ошибка при выполнении запроса: " << sqlite3_errmsg(db) << std::endl;
    }
    sqlite3_finalize(stmt);
    std::cout << "result" << std::endl;
    auto r = processor(result);
    return r;
}

std::vector<std::vector<std::string>> DatabaseManager::processor(std::vector<std::vector<std::string>> matrix)
{
    int rows = matrix.size();
    std::cout << "rows " << rows << std::endl;
    if (rows == 0)
    {
        return matrix;
    }
    int cols = matrix[0].size();

    std::cout << "rows " << rows << std::endl;
    std::cout << "cols " << cols << std::endl;

    std::vector<std::vector<std::string>> result(cols, std::vector<std::string>(rows));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
