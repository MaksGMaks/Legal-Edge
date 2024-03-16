#pragma once

#include "../Endpoints.hpp"
#include "../dataTypes.hpp"

class IDataSerializer
{
public:
    virtual ~IDataSerializer() = default;

    virtual std::string serialize(const Dataset &dataset) = 0;
    virtual Dataset deserialize(const std::string &serialized) = 0;
};