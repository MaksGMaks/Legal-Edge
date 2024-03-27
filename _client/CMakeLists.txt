# CMakeLists.txt в подкаталоге _client
project(client)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Network)

include_directories(${Boost_INCLUDE_DIRS})

set(UI_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Ui")
set(NET_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Network")

set(UI_SOURCES
    ${UI_PATH}/MainWindow.cpp
    ${UI_PATH}/UiManager.cpp
    ${UI_PATH}/MenuBar.cpp
    ${UI_PATH}/Style.hpp)

set(ALL_SOURCES
    ${UI_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/LegalEdgeClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(client ${ALL_SOURCES})

target_link_libraries(client PRIVATE ${Boost_LIBRARIES})

# Вместо "Boost::asio" используйте "Boost::system"
target_link_libraries(client PRIVATE Boost::system)

# Если используются библиотеки Windows Sockets, добавьте следующую строку
target_link_libraries(client PRIVATE ws2_32)

target_link_libraries(client PRIVATE 
    Qt6::Core 
    Qt6::Widgets 
    Qt6::Gui 
    Qt6::Network 
)


# target_link_libraries(client PRIVATE ${CONAN_LIBS})