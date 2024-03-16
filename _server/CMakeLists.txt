cmake_minimum_required(VERSION 3.23)
project(Server)

find_package(Boost REQUIRED)

# include_directories(${Boost_INCLUDE_DIRS})
# Link libs


set(NETWORKING 
    ${CMAKE_CURRENT_SOURCE_DIR}/network/HttpTransaction.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/ThreadPool.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${NETWORKING})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    boost::boost
    $<$<PLATFORM_ID:Windows>:Ws2_32>
    $<$<PLATFORM_ID:Windows>:Wsock32>
)
# target_link_libraries(Server PRIVATE ${Boost_LIBRARIES} ws2_32)
# target_link_libraries(Server PRIVATE ${CONAN_LIBS})



set(NETWORKING 
    ${CMAKE_CURRENT_SOURCE_DIR}/network/HttpServer.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/network/ThreadPool.cpp
)
