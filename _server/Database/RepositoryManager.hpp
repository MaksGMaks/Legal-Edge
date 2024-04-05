#pragma once

#include "DatabaseManager.hpp"
#include "UserRepository.hpp"
#include "CustomerRepository.hpp"

#include <iostream>
#include <memory>

class RepositoryManager
{
public:
    RepositoryManager(const std::shared_ptr<DatabaseManager> &db_manager);

    [[nodiscard]] auto getUsersRepository() -> std::shared_ptr<UserRepository>;
    [[nodiscard]] auto getCustomerRepository() -> std::shared_ptr<CustomerRepository>;

private:
    std::shared_ptr<DatabaseManager> m_db_manager;

    std::shared_ptr<UserRepository> m_userRepo;
    std::shared_ptr<CustomerRepository> m_customerRepo;
};