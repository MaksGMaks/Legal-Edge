#include "ApiManager.hpp"
#include <fstream>

ApiManager::ApiManager(NetworkService &networkService) : m_networkService(&networkService)
{
    qDebug() << "ApiManager::ApiManager";
    // connect(&m_networkService, &NetworkService::responseReceived,
    //         this, &ApiManager::handleResponse);
}

bool fileExists(const QString &filename)
{
    std::ifstream file(filename.toStdString());
    return file.good(); // Проверяем, успешно ли открыт файл
}

ApiManager::~ApiManager()
{
    qDebug() << "ApiManager::~ApiManager";
}

void ApiManager::loginUser(const QString &username, const QString &password)
{
    Dataset dataset;
    dataset[Keys::User::USERNAME] = {username};
    dataset[Keys::User::PASSWORD] = {password};

    m_networkService->sendRequest(Endpoints::Users::LOGIN, Method::POST, dataset);
}

void ApiManager::registerUser(const QString &username, const QString &password)
{
    Dataset dataset;
    dataset[Keys::User::USERNAME] = {username};
    dataset[Keys::User::PASSWORD] = {password};

    m_networkService->sendRequest(Endpoints::Users::REGISTER, Method::POST, dataset);
}

void ApiManager::sendPDFfile(const QString &path)
{
    Dataset dataset;
    if (!fileExists(path))
    {
        QString ex = "file - " + path + " does not exist";
        throw std::runtime_error(ex.toStdString());
    }

    // implementation

    dataset[Keys::File::PDF] = {};
}

void ApiManager::addNewCustomer(const QString &username, const QString &phone)
{
    Dataset dataset;
    dataset[Keys::Customer::USERNAME] = {username};
    dataset[Keys::Customer::PHONE] = {phone};

    m_networkService->sendRequest(
        Endpoints::Customer::ADD,
        Method::POST,
        dataset);
}

void ApiManager::addNewNote(const QString &text, const QString &datetime)
{
    Dataset dataset;
    dataset[Keys::Notes::TEXT] = {text};
    dataset[Keys::Notes::DATE] = {datetime};

    m_networkService->sendRequest(
        Endpoints::Notes::ADD,
        Method::POST,
        dataset);
}