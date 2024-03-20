#pragma once

#include "../dataTypes.hpp"
#include "../Endpoints.hpp"

class IBusinessModule
{
public:
    virtual ~IBusinessModule() = default;
    virtual ResponseData executeTask(const RequestData &requestData) = 0;
};