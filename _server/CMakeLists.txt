cmake_minimum_required(VERSION 3.12)
project(Server)

find_package(Boost REQUIRED)
find_package(nlohmann_json REQUIRED)

set(NETWORKING 
    ${CMAKE_CURRENT_SOURCE_DIR}/network/HttpTransaction.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/ThreadPool.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/JsonSerializer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${NETWORKING})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    boost::boost
    nlohmann_json::nlohmann_json
    $<$<PLATFORM_ID:Windows>:Ws2_32>
    $<$<PLATFORM_ID:Windows>:Wsock32>
)