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
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Define source files
set(SOURCES
        main.cpp
        src/CommandOption.cpp
        src/interfaces/ICommand.cpp
        src/interfaces/ICommandWithOptions.cpp
        src/IndexerCommand.cpp
        src/IndexerCommandOption.cpp
        src/GetCommand.cpp
        src/ClearCommand.cpp
        src/AddCommand.cpp
        src/PushCommand.cpp
        src/SearchCommand.cpp
        src/interfaces/ISearchCommandOption.cpp
        src/DateOption.cpp
        src/SizeOption.cpp
        src/TypeListOption.cpp
        src/SizeExOption.cpp
        src/TypeOption.cpp
        src/Debugging.cpp
        src/lexer.cpp
)

# Define header files
set(HEADERS
        includes/CommandOption.h
        includes/interfaces/ICommand.h
        includes/interfaces/ICommandWithOptions.h
        includes/IndexerCommand.h
        includes/IndexerCommandOption.h
        includes/enums/EnumOption.h
        includes/GetCommand.h
        includes/AddCommand.h
        includes/ClearCommand.h
        includes/PushCommand.h
        includes/SearchCommand.h
        includes/interfaces/ISearchCommandOption.h
        includes/DateOption.h
        includes/SizeOption.h
        includes/TypeListOption.h
        includes/SizeExOption.h
        includes/TypeOption.h
        includes/Debugging.h
        includes/lexer.h
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
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core)

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