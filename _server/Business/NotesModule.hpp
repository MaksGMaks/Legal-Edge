#pragma once

#include "IBusienessModule.hpp"
#include "../Database/RepositoryManager.hpp"

#include <memory>

class NotesModule : public IBusinessModule
{
public:
    NotesModule(std::shared_ptr<RepositoryManager> rManager);
    virtual ResponseData executeTask(const RequestData &requestData) override;

private:
    ResponseData addNewNote(const Dataset &dataset);
    ResponseData deleteNote(const Dataset &dataset);
    ResponseData getAllNotes();
    ResponseData editNotes(const Dataset &dataset);

    ResponseData createCase(const Dataset &dataset);
    ResponseData editCase(const Dataset &dataset);
    ResponseData deleteCase(const Dataset &dataset);
    ResponseData getAllCases();

private:
    std::shared_ptr<IRepository> m_NotesRepository;
    std::shared_ptr<IRepository> m_CaseRepository;
};
