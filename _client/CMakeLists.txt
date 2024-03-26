# CMakeLists.txt в подкаталоге _client
project(client)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Network)

include_directories(${Boost_INCLUDE_DIRS})

set(UI_SOURCES
    Ui\MainWindow.cpp
    Ui\UiManager.cpp
    Ui\MenuBar.cpp
    Ui\Style.hpp)

add_executable(client main.cpp)

target_link_libraries(client PRIVATE ${Boost_LIBRARIES})

# Вместо "Boost::asio" используйте "Boost::system"
target_link_libraries(client PRIVATE Boost::system)

# Если используются библиотеки Windows Sockets, добавьте следующую строку
target_link_libraries(client PRIVATE ws2_32)

# target_link_libraries(client PRIVATE ${CONAN_LIBS})