#include "IBusienessModule.hpp"

class UserModule : public IBusinessModule
{
public:
    UserModule();
    virtual ResponseData executeTask(const RequestData &requestData) override;

private:
    ResponseData loginUser(const Dataset &dataset);

    ResponseData registerUser(const Dataset &dataset);
};