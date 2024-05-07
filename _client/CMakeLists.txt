project(client)

# Locate Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Network Pdf PdfWidgets)
find_package(Boost REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(UI_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Ui")
set(NET_PATH "${CMAKE_CURRENT_SOURCE_DIR}/network")
set(READ_PATH "${CMAKE_CURRENT_SOURCE_DIR}/FilesReader")
set(BOOKS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Ui/books")

set(PDF_DEST_DIR ${CMAKE_CURRENT_BINARY_DIR}/books)

set(UI_SOURCES
    ${UI_PATH}/MainWindow.cpp
    ${UI_PATH}/UiManager.cpp
    ${UI_PATH}/Widgets/SubWidgets/Style.hpp
    ${UI_PATH}/Widgets/CaseManagment.cpp
    ${UI_PATH}/Widgets/Helper.cpp
    ${UI_PATH}/Widgets/Plans.cpp
    ${UI_PATH}/Widgets/SubWidgets/AddEvent.cpp
    ${UI_PATH}/Widgets/SubWidgets/MyCases.cpp
    ${UI_PATH}/Widgets/SubWidgets/NewEvent.cpp
    ${UI_PATH}/Widgets/SubWidgets/BooksOfLaws.cpp
    ${UI_PATH}/Widgets/SubWidgets/PdfReader.cpp
    ${UI_PATH}/Widgets/SubWidgets/SearchFieldComp.cpp
    ${UI_PATH}/Widgets/SubWidgets/InputAreaComp.cpp
    ${UI_PATH}/Widgets/SubWidgets/CreateCase.cpp
    )

set(BOOKS_SOURCES
    ${BOOKS_PATH}/administrativeJudiciaryCodex.pdf
    ${BOOKS_PATH}/administrativeOffensesCodex.pdf
    ${BOOKS_PATH}/airCodex.pdf
    ${BOOKS_PATH}/budgetCodex.pdf
    ${BOOKS_PATH}/civilCodex.pdf
    ${BOOKS_PATH}/civilProcedureCodex.pdf
    ${BOOKS_PATH}/civilProtectionCodex.pdf
    ${BOOKS_PATH}/criminalAndExecutiveCodex.pdf
    ${BOOKS_PATH}/criminalCodex.pdf
    ${BOOKS_PATH}/criminalProcedureCodex.pdf
    ${BOOKS_PATH}/customsCodex.pdf
    ${BOOKS_PATH}/economicCodex.pdf
    ${BOOKS_PATH}/economicProcedualCodex.pdf
    ${BOOKS_PATH}/electionCodex.pdf
    ${BOOKS_PATH}/familyCodex.pdf
    ${BOOKS_PATH}/forestCodex.pdf
    ${BOOKS_PATH}/housingCodex.pdf
    ${BOOKS_PATH}/labourCodex.pdf
    ${BOOKS_PATH}/landCodex.pdf
    ${BOOKS_PATH}/merchantMaritimeCodex.pdf
    ${BOOKS_PATH}/proceduresBankruptcyCodex.pdf
    ${BOOKS_PATH}/subsoilCodex.pdf
    ${BOOKS_PATH}/taxCodex.pdf
    ${BOOKS_PATH}/waterCodex.pdf
    )

set(READER_SOURCE
    ${READ_PATH}/Reader.cpp)

set(NET_SOURCES 
    ${NET_PATH}/NetworkService.cpp
    ${NET_PATH}/ApiManager.cpp
    ${NET_PATH}/JsonSerializer.cpp
    )

set(MAIN_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/LegalEdgeClient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dataTypes.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    )

set(ALL_SOURCES
    ${UI_SOURCES}
    ${NET_SOURCES}
    ${MAIN_SOURCES}
    ${READER_SOURCE}
    ${BOOKS_SOURCES}
)

add_executable(${PROJECT_NAME} ${ALL_SOURCES})

# Створити ціль для копіювання PDF файлів
add_custom_target(copy_books
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${BOOKS_PATH} ${PDF_DEST_DIR}
    COMMENT "Copying PDF files to build directory"
)

# Додати залежність від цілі copy_books
add_dependencies(${PROJECT_NAME} copy_books)

# Link libraries 
target_link_libraries(${PROJECT_NAME} 
    PUBLIC
    $<$<PLATFORM_ID:Windows>:Ws2_32>
    $<$<PLATFORM_ID:Windows>:Wsock32>
    Qt6::Core 
    Qt6::Widgets 
    Qt6::Gui 
    Qt6::Network
    Qt6::Pdf
    Qt6::PdfWidgets
)



