#include "JsonSerializer.hpp"

QByteArray JsonSerializer::serialize(const Dataset &dataset)
{
    QJsonObject jsonObject;
    for (auto it = dataset.constBegin(); it != dataset.constEnd(); ++it)
    {
        QJsonArray jsonRow;
        for (const QString &cell : it.value())
        {
            jsonRow.append(QJsonValue(cell));
        }
        jsonObject.insert(it.key(), jsonRow);
    }

    QJsonDocument doc(jsonObject);
    return doc.toJson(QJsonDocument::Compact);
}

Dataset JsonSerializer::deserialize(const QByteArray &serialized)
{
    Dataset dataset;
    QJsonDocument doc = QJsonDocument::fromJson(serialized);

    if (!doc.isObject())
    {
        qDebug() << "Invalid JSON document";
        return dataset;
    }

    QJsonObject jsonObject = doc.object();
    for (auto it = jsonObject.constBegin(); it != jsonObject.constEnd(); ++it)
    {
        if (!it.value().isArray())
        {
            qDebug() << "Invalid JSON array for key: " << it.key().toStdString();
            continue;
        }

        QStringList row;
        QJsonArray jsonRow = it.value().toArray();
        for (const QJsonValue &cellValue : jsonRow)
        {
            row.append(cellValue.toString());
        }
        dataset.insert(it.key(), row);
    }

    return dataset;
}