#include "NotesModule.hpp"
#include <iostream>

NotesModule::NotesModule(std::shared_ptr<RepositoryManager> rManager)
{
    m_NotesRepository = std::move(rManager->getNotesRepoditory());
    std::cout << "NotesModule::NotesModule" << std::endl;
}

ResponseData NotesModule::executeTask(const RequestData &requestData)
{
    std::cout << "NotesModule::executeTask() - " << std::endl;
    ResponseData response;
    if (requestData.submodule == "add" && requestData.method == "POST")
    {
        response = addNewNote(requestData.dataset);
    }
    if (requestData.submodule == "del" && requestData.method == "DEL")
    {
        response = deleteNote(requestData.dataset);
    }
    if (requestData.submodule == "get" && requestData.method == "GET")
    {
        response = getAllNotes();
    }
    if (requestData.submodule == "upd" && requestData.method == "PULL")
    {
        response = editNotes(requestData.dataset);
    }
    return response;
}

ResponseData NotesModule::addNewNote(const Dataset &dataset)
{
    std::cout << "NotesModule::addNewNote" << std::endl;
    auto text = dataset.at(Keys::Notes::TEXT).front();
    auto date = dataset.at(Keys::Notes::DATE).front();
    m_NotesRepository->add({text, date});
    ResponseData res;
    return res;
}

ResponseData NotesModule::getAllNotes()
{
    std::cout << "NotesModule::getAllNotes" << std::endl;
    ResponseData res;
    auto vec = m_NotesRepository->getAll();
    res.dataset[Keys::Notes::TEXT] = vec[Database::Notes::DATABASE_NOTES_TEXT];
    res.dataset[Keys::Notes::DATE] = vec[Database::Notes::DATABASE_NOTES_DATE];
    return res;
}

ResponseData NotesModule::deleteNote(const Dataset &dataset)
{
    std::cout << "NotesModule::deleteNote" << std::endl;
    auto date = dataset.at(Keys::Notes::DATE).front();
    m_NotesRepository->deleteResource(date);
    ResponseData res;
    return res;
}

ResponseData NotesModule::editNotes(const Dataset &dataset)
{
    std::cout << "NotesModule::editNotes" << std::endl;
    auto text = dataset.at(Keys::Notes::TEXT).front();
    auto date = dataset.at(Keys::Notes::DATE).front();
    m_NotesRepository->update({text, date});
    ResponseData res;
    return res;
}