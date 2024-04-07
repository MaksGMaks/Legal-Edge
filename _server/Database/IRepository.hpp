#pragma once

#include "../DataTypes.hpp"

class IRepository
{
public:
    virtual ~IRepository() = default;

    // virtual void add(const T &entity) = 0;
    // virtual void update(const T &entity) = 0;
    // virtual void deleteResource(const std::string &id) = 0;
    virtual std::vector<std::list<std::string>> getByField(const std::string &fieldName, const std::string &value) const = 0;
    virtual std::vector<std::list<std::string>> getAll() const = 0;
};