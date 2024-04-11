#include "UserRepository.hpp"

#include <iostream>

UserRepository::UserRepository(std::shared_ptr<DatabaseManager> dbManager) : m_dbManager{dbManager}
{
    std::cout << "UserRepository::UserRepository" << std::endl;
}

UserRepository::~UserRepository()
{
    std::cout << "UserRepository::~UserRepository" << std::endl;
}

std::vector<std::vector<std::string>> UserRepository::getByField(const std::string &fieldName, const std::string &value) const
{
    std::cout << "UsersRepository::getByField | {} = {} " << fieldName << ", " << value << std::endl;
    const std::string query = "SELECT ID, USERNAME, PASSWORD FROM Users WHERE " + fieldName + " = ?;";
    auto result = m_dbManager->executeQuery(query, {value});
    return result;
}

std::vector<std::vector<std::string>> UserRepository::getAll() const
{
    std::cout << "UserRepository::getAll" << std::endl;
    const std::string query = "SELECT * FROM Users";
    auto result = m_dbManager->executeQuery(query);
    return result;
}

void UserRepository::add(const std::initializer_list<std::string> &lst)
{
    std::cout << "UserRepository::add" << std::endl;
    const std::string query = "INSERT INTO Users (id, username, password) VALUES(?,?,?)";
    auto res = m_dbManager->executeQuery(query, lst);
}