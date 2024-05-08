#include "ApiManager.hpp"
#include "../FilesReader/Reader.hpp"

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

void ApiManager::setupHandlers()
{
    m_responseHandlers[Endpoints::Users::LOGIN] = [this](Method method, const Dataset &dataset)
    { handleLoginResponse(method, dataset); };
    // m_responseHandlers[Endpoints::Users::REGISTER] = [this](Method method, const Dataset &dataset)
    // { handleRegistrationResponse(method, dataset); };
    // m_responseHandlers[Endpoints::Users::ROLES] = [this](Method method, const Dataset &dataset)
    // { handleRoles(method, dataset); };
}

void ApiManager::handleResponse(const QString &endpoint, Method method, const Dataset &dataset)
{
    qDebug("ApiManager::handleResponse for endpoint={}", endpoint);
    auto handler = m_responseHandlers.find(endpoint);
    handler->second(method, dataset);
}

void ApiManager::createCase(const QString &name, const QList<QString> &files)
{
    Reader reader;
    qDebug() << "ApiManager::createCase";
    QString nameDir = name;
    QString path = QString("%1/%2").arg(PATH_CASE, nameDir);
    QDir dir;
    dir.mkpath(path);
    auto absolute = dir.absolutePath();
    for (auto file : files)
    {
        reader.moveToDirByPath(file, absolute);
    }
    Dataset dataset;
    dataset[Keys::Case::NAME] = {name};
    dataset[Keys::Case::PATH] = {absolute};
    dataset[Keys::Case::STATUS] = {Keys::Case::Status::inProgress};
    m_networkService.sendRequest(Endpoints::Case::ADD, Method::POST, dataset);
}

void ApiManager::getAllCases()
{
    qDebug() << "ApiManager::getAllCases";
    Dataset dataset;
    m_networkService.sendRequest(Endpoints::Case::GET, Method::GET, dataset);
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