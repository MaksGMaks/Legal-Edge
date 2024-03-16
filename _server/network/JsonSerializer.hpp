#pragma once

#include "IDataSerializer.hpp"

class JsonSerializer : public IDataSerializer
{
public:
    virtual std::string serialize(const Dataset &dataset);
    virtual Dataset deserialize(const std::string &serialized);
};
