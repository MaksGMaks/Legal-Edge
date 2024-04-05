#include "CustomerRepository.hpp"
#include <iostream>

CustomerRepository::CustomerRepository()
{
    std::cout << "CustomerRepository::CustomerRepository" << std::endl;
}

std::vector<std::vector<std::string>> CustomerRepository::getByField(const std::string &fieldName, const std::string &value) const
{
    std::vector<std::vector<std::string>> res;
    std::cout << "CustomerRepository::getByField" << std::endl;
    // do smth
    return res;
}

std::vector<std::vector<std::string>> CustomerRepository::getAll() const
{
    std::vector<std::vector<std::string>> res;
    std::cout << "CustomerRepository::getAll" << std::endl;
    // do smth
    return res;
}
