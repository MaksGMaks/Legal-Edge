#include "UserModule.hpp"
#include <iostream>

UserModule::UserModule(std::shared_ptr<RepositoryManager> rManager)
{
    m_userRepository = std::move(rManager->getUsersRepository());
    std::cout << "UserModule::UserModule - " << std::endl;
}

ResponseData UserModule::executeTask(const RequestData &requestData)
{
    std::cout << "UserModule::executeTask() - " << std::endl;

    ResponseData response;
    std::cout << "MODULE ---> " << requestData.module << std::endl;
    if (requestData.submodule == "login" && requestData.method == "POST")
    {
        response = loginUser(requestData.dataset);
    }

    if (requestData.submodule == "register" && requestData.method == "POST")
    {
        response = registerUser(requestData.dataset);
    }

    std::cout << std::endl;
    std::cout << "USERNAME ------> " << requestData.dataset.at(Keys::User::USERNAME).front() << std::endl;
    std::cout << "PASSWORD ------> " << requestData.dataset.at(Keys::User::PASSWORD).front() << std::endl;
    std::cout << std::endl;
    ResponseData r;
    return r;
}

ResponseData UserModule::loginUser(const Dataset &dataset)
{
    std::cout << "UserModule::loginUser() - " << std::endl;
    // call userRepository
    ResponseData response;
    auto username = dataset.at(Keys::User::USERNAME).front();
    auto password = dataset.at(Keys::User::PASSWORD).front();
    auto vec = m_userRepository->getByField(Keys::User::USERNAME, username);
    std::cout << "POSLE" << std::endl;
    for (auto i : vec)
    {
        std::cout << "i[1] - " << i[1] << std::endl;
        std::cout << "username - " << username << std::endl;
        if (i[1] == username)
        {
            std::cout << "YES, YES, YES" << std::endl;
        }
    }
    // auto result = m_db->executeQuery("SELECT * FROM users WHERE USERNAME = ? AND PASSWORD = ?", {username, password});

    // std::cout << "-----RESULTS----" << std::endl;
    // std::cout << "CONTAINS ----> " << result.contains << std::endl;
    // std::cout << "ERRORS ----> " << result.dataset.at(Keys::_ERROR).front() << std::endl;
    ResponseData r;
    r.dataset[Keys::User::USERNAME] = {username};
    return r;
}

ResponseData UserModule::registerUser(const Dataset &dataset)
{
    std::cout << "UserModule::registerUser() - " << std::endl;
    // call userRepository
    ResponseData r;
    return r;
}