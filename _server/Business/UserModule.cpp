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
    return response;
}

ResponseData UserModule::loginUser(const Dataset &dataset)
{
    std::cout << "UserModule::loginUser() - " << std::endl;
    ResponseData response;
    auto username = dataset.at(Keys::User::USERNAME).front();
    auto password = dataset.at(Keys::User::PASSWORD).front();
    auto vec = m_userRepository->getByField(Keys::User::USERNAME, username);
    if (!vec.empty())
    {
        response.dataset[Keys::User::USERNAME] = {vec[0][Database::Users::DATABASE_USER_USERNAME]};
    }
    else
    {
        std::cout << "user does not exist" << std::endl;
        throw std::runtime_error("user does not exist");
    }
    response.dataset[Keys::User::USERNAME] = {vec[0][Database::Users::DATABASE_USER_USERNAME]};
    return response;
}

ResponseData UserModule::registerUser(const Dataset &dataset)
{
    std::cout << "UserModule::registerUser() - " << std::endl;
    // test id:
    std::string id = "12";
    // test id||
    ResponseData res;
    auto username = dataset.at(Keys::User::USERNAME).front();
    auto password = dataset.at(Keys::User::PASSWORD).front();
    auto vec = m_userRepository->getByField(Keys::User::USERNAME, username);
    if (vec.empty())
    {
        m_userRepository->add({id, username, password});
    }
    else
    {
        std::cout << "already exist" << std::endl;
    }
    return res;
}