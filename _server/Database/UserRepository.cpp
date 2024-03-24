#include "UserRepository.hpp"

#include <iostream>

UserRepository::UserRepository(std::shared_ptr<DatabaseManager> dbManager) : m_dbManager{dbManager}
{
    std::cout << "UserRepository::UserRepository" << std::endl;
}

std::vector<std::vector<std::string>> UserRepository::getByField(const std::string &fieldName, const std::string &value) const
{
    std::cout << "UsersRepository::getByField | {} = {} " << fieldName << ", " << value << std::endl;
    // std::vector<User> users;

    const std::string query = "SELECT ID, USERNAME, PASSWORD FROM Users WHERE " + fieldName + " = ?;";
    auto result = m_dbManager->executeQuery(query, {value});

    // while (result && result->next())
    //     users.emplace_back(userFromCurrentRow(result));

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