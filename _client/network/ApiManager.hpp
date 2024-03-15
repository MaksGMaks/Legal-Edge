#include <QObject>
#include <QSharedPointer>

#include "NetworkService.hpp"

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

signals:
    void loginSuccess(const QString &id, const QString &roleId);
    void registrationSuccess();

private:
private:
    QSharedPointer<NetworkService> m_networkService;
    QMap<QString, ResponseHandler> m_responseHandlers;
};