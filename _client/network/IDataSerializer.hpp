#pragma once

#include "..\dataTypes.hpp"

#include <QByteArray>

class IDataSerializer
{
public:
    virtual ~IDataSerializer() = default;

    virtual QByteArray serialize(const Dataset &dataset) = 0;
    virtual Dataset deserialize(const QByteArray &serialized) = 0;
};
