#include "ApiManager.hpp"
#include <fstream>

ApiManager::ApiManager(NetworkService &networkService) : m_networkService(networkService)
{
    qDebug() << "ApiManager::ApiManager";
    connect(&m_networkService, &NetworkService::responseReceived,
            this, &ApiManager::handleResponse);
    // connect(m_networkService, &NetworkService::responseReceived,
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
}

void ApiManager::loginUser(const QString &username, const QString &password)
{
    Dataset dataset;
    dataset[Keys::User::USERNAME] = {username};
    dataset[Keys::User::PASSWORD] = {password};

    m_networkService.sendRequest(Endpoints::Users::LOGIN, Method::POST, dataset);
}

void ApiManager::registerUser(const QString &username, const QString &password)
{
    Dataset dataset;
    dataset[Keys::User::USERNAME] = {username};
    dataset[Keys::User::PASSWORD] = {password};

    m_networkService.sendRequest(Endpoints::Users::REGISTER, Method::POST, dataset);
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

    m_networkService.sendRequest(
        Endpoints::Customer::ADD,
        Method::POST,
        dataset);
}

void ApiManager::addNewNote(const QString &text, const QString &datetime)
{
    Dataset dataset;
    dataset[Keys::Notes::TEXT] = {text};
    dataset[Keys::Notes::DATE] = {datetime};

    m_networkService.sendRequest(
        Endpoints::Notes::ADD,
        Method::POST,
        dataset);
}

void ApiManager::deleteNote(const QString &datetime)
{
    Dataset dataset;
    dataset[Keys::Notes::DATE] = {datetime};

    m_networkService.sendRequest(
        Endpoints::Notes::DEL,
        Method::DEL,
        dataset);
}

void ApiManager::getAllNotes()
{
    Dataset dataset;

    m_networkService.sendRequest(
        Endpoints::Notes::GET,
        Method::GET,
        dataset);
}

void ApiManager::editNote(const QString &text, const QString &datetime)
{
    Dataset dataset;
    dataset[Keys::Notes::TEXT] = {text};
    dataset[Keys::Notes::DATE] = {datetime};

    m_networkService.sendRequest(
        Endpoints::Notes::UPD,
        Method::PUT,
        dataset);
}

void ApiManager::handleLoginResponse(Method method, const Dataset &dataset)
{
    try
    {
        const auto &id_list = dataset[Keys::User::ID];
        const auto &role_id_list = dataset[Keys::User::ROLE_ID];

        if (id_list.empty() || role_id_list.empty())
        {
            qDebug() << "Invalid login credentials";
            return;
        }

        const std::string &id = id_list.first().toStdString();
        const std::string &roleId = role_id_list.first().toStdString();

        if (id.empty() || roleId.empty())
        {
            qDebug() << "Invalid login id or role id";
        }
        else
        {
            emit loginSuccess(QString::fromStdString(id), QString::fromStdString(roleId));
        }
    }
    catch (const std::out_of_range &e)
    {
        qDebug() << "ApiManager::handleLoginResponse | missing key in dataset";
    }
}

void ApiManager::handleAllNotes(Method method, const Dataset &dataset)
{
    Notes note;
    for (int i = 0; i < dataset[Keys::Notes::TEXT].size(); i++)
    {
        std::string text = dataset[Keys::Notes::TEXT][i].toStdString();
        std::string date = dataset[Keys::Notes::DATE][i].toStdString();

        note.push_back(std::make_pair<std::string, std::string>(std::move(text), std::move(date)));
    }
    emit getAllNotesSuccess(note);
}