#pragma once

#include <iostream>
#include <sqlite3.h>
#include <mutex>

#include "../dataTypes.hpp"

class DatabaseManager
{
private:
    const std::string m_path_to_db;
    const std::string m_configure_path;

    std::mutex m_mutex;

    sqlite3 *db;

public:
    DatabaseManager(const std::string &path_to_db, const std::string &path_to_sql_script) noexcept;
    ~DatabaseManager();

    // dbResponse executeQuery(const std::string &query, const std::vector<std::string> &params);
    std::vector<std::vector<std::string>> executeQuery(const std::string &query, const std::vector<std::string> &params);
    std::vector<std::vector<std::string>> executeQuery(const std::string &query);

    // void selectTest();

    void start();
};
