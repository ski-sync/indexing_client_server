cmake_minimum_required(VERSION 3.16)

project(indexing_client_server VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Qt settings
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "~/Qt/6.7.3/macos")

# Find Qt packages
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Sql)

# Define source files
set(SOURCES
        main.cpp
        src/lexer.cpp
        src/Bdd.cpp
        src/Debugging.cpp
        src/Line.cpp
        src/Indexer.cpp
        src/IndexerThread.cpp
        src/interface/IState.cpp
        src/search_command/Created.cpp
        src/search_command/Size.cpp
        src/command/Add.cpp
        src/command/Clear.cpp
        src/command/Get.cpp
        src/command/IndexerCommand.cpp
        src/command/Push.cpp
        src/command/Search.cpp
)

# Define header files
set(HEADERS
        includes/lexer.h
        includes/Bdd.h
        includes/Debugging.h
        includes/Line.h
        includes/Indexer.h
        includes/IndexerThread.h
        includes/interface/IState.h
        includes/enum/FsmEnum.h
        includes/enum/CommandEnum.h
        includes/search_command/Created.h
        includes/search_command/Size.h
        includes/enum/OptionEnum.h
        includes/interface/ICommand.h
        src/interface/ICommand.cpp
        includes/command/Search.h
        includes/command/Add.h
        includes/command/IndexerCommand.h
        includes/command/Get.h
        includes/command/Push.h
        includes/command/Clear.h
        includes/enum/ListTypeEnum.h
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Set include directories
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/interfaces
        ${CMAKE_CURRENT_SOURCE_DIR}/include/enums
)

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql)

# Installation
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Enable testing
enable_testing()

# Add a custom target for running tests
add_custom_target(run_tests
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        DEPENDS ${PROJECT_NAME}
)

# Optional: Add compilation flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)