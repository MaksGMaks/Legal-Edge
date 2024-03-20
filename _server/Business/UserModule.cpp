#include "UserModule.hpp"

#include <iostream>

UserModule::UserModule()
{
    std::cout << "UserModule::UserModule - " << std::endl;
}

ResponseData UserModule::executeTask(const RequestData &requestData)
{
    std::cout << "UserModule::executeTask() - " << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    auto j = requestData.dataset.at(Keys::User::USERNAME);
    std::string k;
    for (auto i : j)
        k = {i};

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    ResponseData r;
    return r;
}