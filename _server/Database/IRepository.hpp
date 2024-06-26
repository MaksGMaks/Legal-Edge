#pragma once

#include "../dataTypes.hpp"
#include <initializer_list>

class IRepository
{
public:
    virtual ~IRepository() = default;

    virtual void add(const std::initializer_list<std::string> &lst) = 0;
    virtual void update(const std::initializer_list<std::string> &lst) = 0;
    virtual void deleteResource(const std::string &datetime) = 0;
    virtual std::vector<std::vector<std::string>> getByField(const std::string &fieldName, const std::string &value) const = 0;
    virtual std::vector<std::vector<std::string>> getAll() const = 0;
};