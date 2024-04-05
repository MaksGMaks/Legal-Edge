cmake_minimum_required(VERSION 3.23)
project(Server)

find_package(Boost REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(SQLite3 REQUIRED)

set(BUSINESS
    ${CMAKE_CURRENT_SOURCE_DIR}/Business/UserModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Business/BusienessLogic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Business/CustomerModule.cpp)

set(DATABASE
    ${CMAKE_CURRENT_SOURCE_DIR}/Database/DatabaseManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Database/RepositoryManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Database/UserRepository.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Database/CustomerRepository.cpp)



set(NETWORKING 
    ${CMAKE_CURRENT_SOURCE_DIR}/network/HttpTransaction.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/ThreadPool.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/JsonSerializer.cpp)


set(SERVER
    ${NETWORKING}
    ${DATABASE}
    ${BUSINESS}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Server.cpp)

set(SERVER_BUILD_DIR "${CMAKE_BINARY_DIR}/_server")


add_executable(${PROJECT_NAME} ${SERVER})

#database
target_compile_definitions(${PROJECT_NAME} PRIVATE
    DB_PATH="${SERVER_BUILD_DIR}/db.sl3"
    DB_SCRIPT="${CMAKE_CURRENT_SOURCE_DIR}/Database/db_configure.sql")

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    boost::boost
    SQLite::SQLite3
    nlohmann_json::nlohmann_json
    $<$<PLATFORM_ID:Windows>:Ws2_32>
    $<$<PLATFORM_ID:Windows>:Wsock32>
)