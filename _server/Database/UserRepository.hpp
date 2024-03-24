#pragma once

#include "IRepository.hpp"
#include "DatabaseManager.hpp"

#include <memory>

class User;

class UserRepository : public IRepository<User>
{
public:
    explicit UserRepository(std::shared_ptr<DatabaseManager> dbManager);
    //     ~UsersRepository() override;

    //     void add(const User &entity) override;
    //     void update(const User &entity) override;
    //     void deleteResource(const std::string &id) override;
    std::vector<std::vector<std::string>> getByField(const std::string &fieldName, const std::string &value) const override;
    //     std::vector<User> getAll() const override;

private:
    // User userFromCurrentRow(const std::shared_ptr<IQueryResult> &queryResult) const;

private:
    std::shared_ptr<DatabaseManager> m_dbManager;
};