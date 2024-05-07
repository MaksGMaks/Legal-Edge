#pragma once

#include "UserRepository.hpp"
#include "CustomerRepository.hpp"
#include "NotesRepository.hpp"
#include "CaseRepository.hpp"

#include <iostream>
#include <memory>

class RepositoryManager
{
public:
    RepositoryManager(const std::shared_ptr<DatabaseManager> &db_manager);

    [[nodiscard]] auto getUsersRepository() -> std::shared_ptr<UserRepository>;
    [[nodiscard]] auto getCustomerRepository() -> std::shared_ptr<CustomerRepository>;
    [[nodiscard]] auto getNotesRepoditory() -> std::shared_ptr<NotesRepository>;
    [[nodiscard]] auto getCaseRepository() -> std::shared_ptr<CaseRepository>;

private:
    std::shared_ptr<DatabaseManager> m_db_manager;

    std::shared_ptr<UserRepository> m_userRepo;
    std::shared_ptr<CustomerRepository> m_customerRepo;
    std::shared_ptr<NotesRepository> m_notesRepo;
    std::shared_ptr<CaseRepository> m_caseRepo;
};