#include "ApiManager.hpp"
ApiManager::ApiManager(NetworkService &networkService) : m_networkService(&networkService)
{
    qDebug() << "ApiManager::ApiManager";
    // connect(&m_networkService, &NetworkService::responseReceived,
    //         this, &ApiManager::handleResponse);
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
