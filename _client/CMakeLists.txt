project(client)

# Locate Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Network)
find_package(Boost REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(UI_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Ui")
set(NET_PATH "${CMAKE_CURRENT_SOURCE_DIR}/network")

set(UI_SOURCES
    ${UI_PATH}/MainWindow.cpp
    ${UI_PATH}/UiManager.cpp
    ${UI_PATH}/Widgets/SubWidgets/Style.hpp
    ${UI_PATH}/Widgets/CaseManagment.cpp
    ${UI_PATH}/Widgets/Helper.cpp
    ${UI_PATH}/Widgets/Plans.cpp
    ${UI_PATH}/Widgets/SubWidgets/AddEvent.cpp
    ${UI_PATH}/Widgets/SubWidgets/MyCases.cpp
    ${UI_PATH}/Widgets/SubWidgets/NewEvent.cpp)

set(NET_SOURCES 
    ${NET_PATH}/NetworkService.cpp
    ${NET_PATH}/ApiManager.cpp
    ${NET_PATH}/JsonSerializer.cpp
    )

set(MAIN_SOURCES
${CMAKE_CURRENT_SOURCE_DIR}/LegalEdgeClient.cpp
${CMAKE_CURRENT_SOURCE_DIR}/dataTypes.hpp
${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

set(ALL_SOURCES
${UI_SOURCES}
${NET_SOURCES}
${MAIN_SOURCES})

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



