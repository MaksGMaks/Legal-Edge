cmake_minimum_required(VERSION 3.12)
project(Server)

add_executable(Server main.cpp)

target_link_libraries(Server PRIVATE ${CONAN_LIBS})