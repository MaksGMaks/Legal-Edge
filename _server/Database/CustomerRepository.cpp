#include "CustomerRepository.hpp"
#include <iostream>

CustomerRepository::CustomerRepository(std::shared_ptr<DatabaseManager> dbManager) : m_dbManager{dbManager}
{
    std::cout << "CustomerRepository::CustomerRepository" << std::endl;
}

std::vector<std::list<std::string>> CustomerRepository::getByField(const std::string &fieldName, const std::string &value) const
{
    std::cout << "CustomerRepository::getByField" << std::endl;
    const std::string query = "SELECT username, phoneNumber FROM Clients WHERE " + fieldName + " = ?;";
    auto res = m_dbManager->executeQuery(query, {value});
    return res;
}

std::vector<std::list<std::string>> CustomerRepository::getAll() const
{
    std::cout << "CustomerRepository::getAll" << std::endl;
    const std::string query = "SELECT * FROM Clients;";
    auto res = m_dbManager->executeQuery(query);
    return res;
}

void CustomerRepository::add(const std::initializer_list<std::string> &lst)
{
    std::cout << "CustomerRepository::add" << std::endl;
    const std::string query = "INSERT INTO clients (username, password) VALUES(?,?)";
    auto res = m_dbManager->executeQuery(query, lst);
}
