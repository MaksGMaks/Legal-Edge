project(client)

# Locate Qt packages
find_package(Boost REQUIRED COMPONENTS system)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Network)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(${Boost_INCLUDE_DIRS})

set(UI_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Ui")
set(NET_PATH "${CMAKE_CURRENT_SOURCE_DIR}/network")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(${Boost_INCLUDE_DIRS})

set(UI_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Ui")
set(NET_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Network")

set(UI_SOURCES
    ${UI_PATH}/MainWindow.cpp
    ${UI_PATH}/UiManager.cpp
    ${UI_PATH}/Style.hpp)

set(ALL_SOURCES
    ${UI_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/LegalEdgeClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(client ${ALL_SOURCES})

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

set(NETWORKING 
    ${NET_PATH}/NetworkService.cpp
    ${NET_PATH}/ApiManager.cpp
    ${NET_PATH}/JsonSerializer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dataTypes.hpp)


set(ALL_SOURCES
    ${UI_SOURCES}
    ${NETWORKING}
    ${CMAKE_CURRENT_SOURCE_DIR}/LegalEdgeClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${ALL_SOURCES})

# Link libraries 
target_link_libraries(${PROJECT_NAME} 
    PUBLIC
    $<$<PLATFORM_ID:Windows>:Ws2_32>
    $<$<PLATFORM_ID:Windows>:Wsock32>
    Qt6::Core 
    Qt6::Widgets 
    Qt6::Gui 
    Qt6::Network
)

