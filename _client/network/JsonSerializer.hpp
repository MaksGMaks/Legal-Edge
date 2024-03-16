#include "IDataSerializer.hpp"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QList>
#include <QStringList>

class JsonSerializer : public IDataSerializer
{
public:
    QByteArray serialize(const Dataset &dataset) override;
    Dataset deserialize(const QByteArray &serialized) override;
};