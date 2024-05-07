#include "RepositoryManager.hpp"

RepositoryManager::RepositoryManager(const std::shared_ptr<DatabaseManager> &db_manager) : m_db_manager(db_manager),
                                                                                           m_userRepo{std::make_shared<UserRepository>(m_db_manager)},
                                                                                           m_customerRepo{std::make_shared<CustomerRepository>(m_db_manager)},
                                                                                           m_notesRepo{std::make_shared<NotesRepository>(m_db_manager)},
                                                                                           m_caseRepo{std::make_shared<CaseRepository>(m_db_manager)}
{
}

auto RepositoryManager::getUsersRepository() -> std::shared_ptr<UserRepository>
{
    return m_userRepo;
}

auto RepositoryManager::getCustomerRepository() -> std::shared_ptr<CustomerRepository>
{
    return m_customerRepo;
}

auto RepositoryManager::getNotesRepoditory() -> std::shared_ptr<NotesRepository>
{
    return m_notesRepo;
}

auto RepositoryManager::getCaseRepository() -> std::shared_ptr<CaseRepository>
{
    return m_caseRepo;
}