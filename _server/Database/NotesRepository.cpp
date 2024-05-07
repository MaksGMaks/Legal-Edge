#include "NotesRepository.hpp"
#include <iostream>

NotesRepository::NotesRepository(std::shared_ptr<DatabaseManager> dbManager) : m_dbManager{dbManager}
{
    std::cout << "NotesRepository::NotesRepository" << std::endl;
}

NotesRepository::~NotesRepository()
{
    std::cout << "NotesRepository::~NotesRepository" << std::endl;
}

void NotesRepository::add(const std::initializer_list<std::string> &lst)
{
    std::cout << "NotesRepository::add" << std::endl;
    const std::string query = "INSERT INTO notes (field, datatime) VALUES(?,?)";
    auto res = m_dbManager->executeQuery(query, lst);
}

std::vector<std::vector<std::string>> NotesRepository::getAll() const
{
    const std::string query = "SELECT * FROM notes";
    auto res = m_dbManager->executeQuery(query);
    return res;
}
std::vector<std::vector<std::string>> NotesRepository::getByField(const std::string &fieldName, const std::string &value) const
{
    std::vector<std::vector<std::string>> res;
    return res;
}

void NotesRepository::update(const std::initializer_list<std::string> &lst)
{
    std::cout << "NotesRepository::update" << std::endl;
    const std::string query = "UPDATE notes SET field = ? WHERE date = ?";
    auto res = m_dbManager->executeQuery(query, lst);
}

void NotesRepository::deleteResource(const std::string &datetime)
{
    std::cout << "NotesRepository::deleteResource" << std::endl;
    const std::string query = "DELETE FROM notes WHERE date = ?";
    auto res = m_dbManager->executeQuery(query, {datetime});
}