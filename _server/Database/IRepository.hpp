#pragma once

#include "../DataTypes.hpp"
#include <initializer_list>

class IRepository
{
public:
    virtual ~IRepository() = default;

    virtual void add(const std::initializer_list<std::string> &lst) = 0;
    // virtual void update(const T &entity) = 0;
    // virtual void deleteResource(const std::string &id) = 0;
    virtual std::vector<std::vector<std::string>> getByField(const std::string &fieldName, const std::string &value) const = 0;
    virtual std::vector<std::vector<std::string>> getAll() const = 0;
};