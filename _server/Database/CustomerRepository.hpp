#pragma once

#include "IRepository.hpp"
#include "DatabaseManager.hpp"
#include <memory>

class CustomerRepository : public IRepository
{
public:
    CustomerRepository(std::shared_ptr<DatabaseManager> dbManager);

    void add(const std::initializer_list<std::string> &lst) override;
    std::vector<std::vector<std::string>> getByField(const std::string &fieldName, const std::string &value) const override;
    std::vector<std::vector<std::string>> getAll() const override;

private:
    std::shared_ptr<DatabaseManager> m_dbManager;
};