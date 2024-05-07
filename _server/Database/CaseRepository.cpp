#include "CaseRepository.hpp"

CaseRepository::CaseRepository(std::shared_ptr<DatabaseManager> dbManager) : m_dbManager(dbManager)
{
    std::cout << "CaseRepository::CaseRepository()" << std::endl;
}

CaseRepository::~CaseRepository()
{
    std::cout << "CaseRepository::~CaseRepository()" << std::endl;
}

void CaseRepository::add(const std::initializer_list<std::string> &lst)
{
    std::string query = "INSERT INTO cases (name, path, status) VALUES (?,?,?)";
    m_dbManager->executeQuery(query, lst);
}

void CaseRepository::deleteResource(const std::string &datetime)
{
    std::string query = "DELETE FROM cases WHERE name = ?";
    m_dbManager->executeQuery(query, {datetime});
}

void CaseRepository::update(const std::initializer_list<std::string> &lst)
{
    std::string query = "UPDATE cases SET status =? WHERE name = ?";
    m_dbManager->executeQuery(query, lst);
}

std::vector<std::vector<std::string>> CaseRepository::getByField(const std::string &fieldName, const std::string &value) const
{
    std::string query = "SELECT * FROM cases WHERE " + fieldName + " = ?";
    auto res = m_dbManager->executeQuery(query, {value});
    return res;
}

std::vector<std::vector<std::string>> CaseRepository::getAll() const
{
    std::string query = "SELECT * FROM cases";
    auto res = m_dbManager->executeQuery(query);
    return res;
}