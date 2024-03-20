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
}