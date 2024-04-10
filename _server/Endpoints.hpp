#pragma once

namespace Endpoints
{
    namespace Segments
    {
        inline constexpr int ROOT = 0;
        inline constexpr int MODULE = 1;
        inline constexpr int SUBMODULE = 2;
        inline constexpr int RESOURCE_ID = 3;
    };

    namespace Users
    {
        inline constexpr char USERS_PREFIX[] = "/users";
        inline constexpr char LOGIN[] = "/users/login";
        inline constexpr char REGISTER[] = "/users/register";
    }
}

namespace Keys
{
    inline constexpr char _ERROR[] = "error";

    namespace User
    {
        inline constexpr char ID[] = "id";
        inline constexpr char USERNAME[] = "username";
        inline constexpr char PASSWORD[] = "password";
        inline constexpr char ROLE_ID[] = "roleId";
    }

    namespace Role
    {
        inline constexpr char ID[] = "id";
        inline constexpr char NAME[] = "name";
    }

    namespace Customer
    {
        inline constexpr char USERNAME[] = "username";
        inline constexpr char PHONE[] = "phone";
    }
}

namespace Database
{
    enum Users
    {
        DATABASE_USER_ID = (int)0,
        DATABASE_USER_USERNAME = (int)1,
        DATABASE_USER_PASSWORD = (int)2
    };

    enum Customer : int
    {
        DATABASE_CUSTOMER_USERNAME,
        DATABASE_CUSTOMER_PHONE
    };
}