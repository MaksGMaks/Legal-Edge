project(client)

# Locate Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Network)
find_package(Boost REQUIRED)
add_executable(client main.cpp)

# Link libraries 
target_link_libraries(client 
    PUBLIC
    Boost::system
    $<$<PLATFORM_ID:Windows>:Ws2_32>
    $<$<PLATFORM_ID:Windows>:Wsock32>
    Qt6::Core 
    Qt6::Widgets 
    Qt6::Gui 
    Qt6::Network
)


