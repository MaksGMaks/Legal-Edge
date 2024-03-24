#pragma once

#include <list>
#include <unordered_map>
#include <string>
#include <functional>

struct RequestData;
struct ResponseData;

using Data = std::list<std::string>;
using Dataset = std::unordered_map<std::string, Data>;
using BusinessLogicCallback = std::function<void(ResponseData)>;

struct RequestData
{
    std::string module;     ///< Main module, that will proceed request, like 'users' or 'sales'.
    std::string submodule;  ///< Module spesific process, like 'login' for users, 'records' for sales.
    std::string method;     ///< The HTTP method of the request, such as 'GET' or 'POST'.
    std::string resourceId; ///< ID of specific resource for methods like PUT or DELETE
    Dataset dataset;
};

struct ResponseData
{
    Dataset dataset;
};

struct dbResponse
{
    int SQL_OK;
    bool contains = false;
    Dataset dataset;
};