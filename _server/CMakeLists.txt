cmake_minimum_required(VERSION 3.23)
project(Server)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Server main.cpp)

target_link_libraries(Server PRIVATE ${Boost_LIBRARIES} ws2_32)



set(NETWORKING 
    ${CMAKE_CURRENT_SOURCE_DIR}/network/HttpServer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/ThreadPool.cpp
)