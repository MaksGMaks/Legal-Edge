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

std::vector<std::list<std::string>> UserRepository::getByField(const std::string &fieldName, const std::string &value) const
{
    std::cout << "UsersRepository::getByField | {} = {} " << fieldName << ", " << value << std::endl;
    const std::string query = "SELECT ID, USERNAME, PASSWORD FROM Users WHERE " + fieldName + " = ?;";
    auto result = m_dbManager->executeQuery(query, {value});
    return result;
}

std::vector<std::list<std::string>> UserRepository::getAll() const
{
    const std::string query = "SELECT * FROM Users";
    auto result = m_dbManager->executeQuery(query);
    return result;
}

// User UserRepository::userFromCurrentRow(const std::shared_ptr<IQueryResult> &queryResult) const
// {
//     return User(
//         queryResult->getString(ID),
//         queryResult->getString(USERNAME),
//         queryResult->getString(PASSWORD),
//         queryResult->getString(ROLE_ID));
// }