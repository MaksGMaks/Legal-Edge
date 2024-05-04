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

ResponseData NotesModule::addNewNote(const Dataset &dataset)
{
    std::cout << "NotesModule::addNewNote" << std::endl;
    auto text = dataset.at(Keys::Notes::TEXT).front();
    auto date = dataset.at(Keys::Notes::DATE).front();
    m_NotesRepository->add({text, date});
    ResponseData res;
    return res;
}