#pragma once

#include <iostream>
#include <sqlite3.h>

class DatabaseManager
{
private:
    const std::string m_path_to_db;
    const std::string m_configure_path;

    sqlite3 *db;

public:
    DatabaseManager(const std::string &path_to_db, const std::string &path_to_sql_script) noexcept;
    ~DatabaseManager();

    void insertTest();

    void selectTest();

    void start();
};
