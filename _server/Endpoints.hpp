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
    namespace Notes
    {
        inline constexpr char USERS_PREFIX[] = "/notes";
        inline constexpr char ADD[] = "/notes/add";
        inline constexpr char GET[] = "/notes/get";
        inline constexpr char DEL[] = "/notes/del";
        inline constexpr char UPD[] = "/notes/upd";
    }
    namespace Case
    {
        inline constexpr char USERS_PREFIX[] = "/case";
        inline constexpr char ADD[] = "/case/add";
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
    namespace Notes
    {
        inline constexpr char TEXT[] = "text";
        inline constexpr char DATE[] = "date";
    }
    namespace Case
    {
        inline constexpr char NAME[] = "name";
        inline constexpr char PATH[] = "path";
        inline constexpr char STATUS[] = "status";
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

    enum Notes : int
    {
        DATABASE_NOTES_TEXT,
        DATABASE_NOTES_DATE
    };
    enum Case : int
    {
        DATABASE_CASE_NAME,
        DATABASE_CASE_PATH,
        DATABASE_CASE_STATUS
    };
}