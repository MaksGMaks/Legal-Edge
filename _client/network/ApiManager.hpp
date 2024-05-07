
#include <QObject>

#include "NetworkService.hpp"

#include "../Endpoints.hpp"
#include "../dataTypes.hpp"

class NetworkService;
enum class Method;

class ApiManager : public QObject
{
    Q_OBJECT

    using ResponseHandler = std::function<void(Method method, const Dataset &)>;
    using Notes = std::vector<std::pair<std::string, std::string>>;

public:
    ApiManager(NetworkService &networkService);
    ~ApiManager();

public slots:
    virtual void loginUser(const QString &username, const QString &password);
    virtual void registerUser(const QString &username, const QString &password);
    virtual void sendPDFfile(const QString &path); // not needed
    virtual void addNewCustomer(const QString &username, const QString &phone);
    virtual void addNewNote(const QString &text, const QString &datetime);
    virtual void deleteNote(const QString &datetime);
    virtual void editNote(const QString &text, const QString &datetime);
    virtual void getAllNotes();

    // cases
    virtual void createCase(const QString &name);

protected slots:
    void handleResponse(const QString &endpoint, Method method, const Dataset &dataset);

signals:
    void loginSuccess(const QString &id, const QString &roleId);
    void registrationSuccess();
    void addCustomerSuccess();
    void addNoteSuccess();
    void deleteNoteSuccess();
    void editNoteSuccess();
    void getAllNotesSuccess(const Notes &notes);

private:
    void setupHandlers();
    void handleLoginResponse(Method method, const Dataset &dataset);
    void handleRegistrationResponse(Method method, const Dataset &dataset);
    void handleAllNotes(Method method, const Dataset &dataset);
    void handleAddNoteResponse(Method method, const Dataset &dataset);

private:
    NetworkService &m_networkService;
    QMap<QString, ResponseHandler> m_responseHandlers;
};