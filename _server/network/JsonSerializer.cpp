#include "JsonSerializer.hpp"

#include <nlohmann/json.hpp>

#include <iostream>

using json = nlohmann::json;

std::string JsonSerializer::serialize(const Dataset &dataset)
{
    std::cout << "JsonSerializer::serialize" << std::endl;
    json jsonObject;

    if (dataset.empty())
    {
        return json({}).dump();
    }

    for (const auto &[key, value] : dataset)
    {
        json jsonRow = json::array();
        for (const auto &cell : value)
        {
            jsonRow.push_back(cell);
        }
        jsonObject[key] = jsonRow;
    }

    return jsonObject.dump();
}

Dataset JsonSerializer::deserialize(const std::string &serializedData)
{
    std::cout << "JsonSerializer::deserialize" << std::endl;

    Dataset dataset;
    auto jsonObject = json::parse(serializedData, nullptr, false);

    if (!jsonObject.is_object())
    {
        std::cout << "Invalid JSON document" << std::endl;
        return dataset;
    }

    for (auto &[key, jsonRow] : jsonObject.items())
    {
        if (!jsonRow.is_array())
        {
            std::cout << "Invalid JSON array for key: " << std::endl;
            continue;
        }

        Data row;
        for (auto &cellValue : jsonRow)
        {
            row.push_back(cellValue.get<std::string>());
        }
        dataset[key] = std::move(row);
    }

    return dataset;
}
