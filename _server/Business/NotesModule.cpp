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