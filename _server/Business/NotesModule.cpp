#include "NotesModule.hpp"
#include <iostream>

NotesModule::NotesModule(std::shared_ptr<RepositoryManager> rManager)
{
    m_NotesRepository = std::move(rManager->getNotesRepoditory());
    m_CaseRepository = std::move(rManager->getCaseRepository());
    std::cout << "NotesModule::NotesModule" << std::endl;
}

ResponseData NotesModule::executeTask(const RequestData &requestData)
{
    std::cout << "NotesModule::executeTask() - " << std::endl;
    ResponseData response;
    if (requestData.module == "notes")
    {
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
    }
    else if (requestData.module == "case")
    {
        if (requestData.submodule == "add" && requestData.method == "POST")
        {
            response = createCase(requestData.dataset);
        }
        if (requestData.submodule == "del" && requestData.method == "DEL")
        {
            response = deleteCase(requestData.dataset);
        }
        if (requestData.submodule == "get" && requestData.method == "GET")
        {
            response = getAllCases();
        }
        if (requestData.submodule == "upd" && requestData.method == "PULL")
        {
            response = editCase(requestData.dataset);
        }
    }
    std::cout << "pryam ne tuta " << std::endl;
    return response;
}

ResponseData NotesModule::createCase(const Dataset &dataset)
{
    std::cout << "NotesModule::createCase" << std::endl;
    auto text = dataset.at(Keys::Case::NAME).front();
    auto path = dataset.at(Keys::Case::PATH).front();
    auto status = dataset.at(Keys::Case::STATUS).front();
    m_CaseRepository->add({text, path, status});
    ResponseData res;
    return res;
}

ResponseData NotesModule::editCase(const Dataset &dataset)
{
    ResponseData res;
    return res;
}

ResponseData NotesModule::deleteCase(const Dataset &dataset)
{
    ResponseData res;
    return res;
}

ResponseData NotesModule::getAllCases()
{
    ResponseData res;
    std::cout << "NotesModule::getAllCases" << std::endl;
    auto response = m_CaseRepository->getAll();
    res.dataset[Keys::Case::NAME] = response[Database::Case::DATABASE_CASE_NAME];
    res.dataset[Keys::Case::PATH] = response[Database::Case::DATABASE_CASE_PATH];
    res.dataset[Keys::Case::STATUS] = response[Database::Case::DATABASE_CASE_STATUS];
    return res;
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
    try
    {
        res.dataset[Keys::Notes::TEXT] = vec[Database::Notes::DATABASE_NOTES_TEXT];
        res.dataset[Keys::Notes::DATE] = vec[Database::Notes::DATABASE_NOTES_DATE];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "to - " << std::endl;
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