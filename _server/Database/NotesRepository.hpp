#pragma once

#include "IRepository.hpp"
#include "DatabaseManager.hpp"

#include <memory>

class NotesRepository : public IRepository
{
public:
    explicit NotesRepository(std::shared_ptr<DatabaseManager> dbManager);
    ~NotesRepository() override;

    void add(const std::initializer_list<std::string> &lst) override;
    void update(const std::initializer_list<std::string> &lst) override;
    void deleteResource(const std::string &datetime) override;
    virtual std::vector<std::vector<std::string>> getByField(const std::string &fieldName, const std::string &value) const override;
    virtual std::vector<std::vector<std::string>> getAll() const override;

private:
    std::shared_ptr<DatabaseManager> m_dbManager;
};
