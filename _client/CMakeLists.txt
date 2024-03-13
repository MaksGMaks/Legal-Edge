project(client)

# Locate Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Network)
find_package(Boost REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(NETWORKING 
    ${CMAKE_CURRENT_SOURCE_DIR}/network/NetworkService.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${NETWORKING})

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



