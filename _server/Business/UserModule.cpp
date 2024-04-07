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
    response.dataset[Keys::User::USERNAME] = vec[Database::Users::USERNAME];
    return response;
}

ResponseData UserModule::registerUser(const Dataset &dataset)
{
    std::cout << "UserModule::registerUser() - " << std::endl;
    // call userRepository
    ResponseData r;
    return r;
}