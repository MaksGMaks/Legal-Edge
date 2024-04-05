#pragma once

#include "IRepository.hpp"

class CustomerRepository : public IRepository
{
public:
    CustomerRepository();

    std::vector<std::vector<std::string>> getByField(const std::string &fieldName, const std::string &value) const override;
    std::vector<std::vector<std::string>> getAll() const override;
};