#include "RepositoryManager.hpp"

#include <memory>

RepositoryManager::RepositoryManager(const std::shared_ptr<DatabaseManager> &db_manager) : m_db_manager(db_manager),
                                                                                           m_userRepo{std::make_shared<UserRepository>(m_db_manager)}
{
    m_db_manager->start();
}

auto RepositoryManager::getUsersRepository() -> std::shared_ptr<IRepository<User>>
{
    return m_userRepo;
}