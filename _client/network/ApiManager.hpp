
#include <QObject>
#include <QSharedPointer>

#include "NetworkService.hpp"

#include <QList>

#include "../Endpoints.hpp"
#include "../dataTypes.hpp"

class NetworkService;
enum class Method;

class ApiManager : public QObject
{
    Q_OBJECT

    using ResponseHandler = std::function<void(Method method, const Dataset &)>;

public:
    ApiManager(NetworkService &networkService);
    ~ApiManager();

public slots:
    virtual void loginUser(const QString &username, const QString &password);
    virtual void registerUser(const QString &username, const QString &password);
    virtual void sendPDFfile(const QString &path); // not needed
    virtual void addNewCustomer(const QString &username, const QString &phone);
    virtual void addNewNote(const QString &text, const QString &datetime);

    // cases
    virtual void createCase(const QString &name, const QList<QString> &files);
    virtual void getAllCases();

protected slots:
    void handleResponse(const QString &endpoint, Method method, const Dataset &dataset);

signals:
    void loginSuccess(const QString &id, const QString &roleId);
    void registrationSuccess();

private:
private:
    QSharedPointer<NetworkService> m_networkService;
    QMap<QString, ResponseHandler> m_responseHandlers;
};