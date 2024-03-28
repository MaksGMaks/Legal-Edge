#include "RepositoryManager.hpp"

#include <memory>

RepositoryManager::RepositoryManager(const std::shared_ptr<DatabaseManager> &db_manager) : m_db_manager(db_manager),
                                                                                           m_userRepo{std::make_shared<UserRepository>(m_db_manager)}
{
}

auto RepositoryManager::getUsersRepository() -> std::shared_ptr<UserRepository>
{
    return m_userRepo;
}