#pragma once

#include "../../dataTypes.hpp"
#include "../../Endpoints.hpp"

class IEntity
{
    virtual Dataset &operator>>(Dataset &dataset) = 0;
};