cmake_minimum_required(VERSION 3.23)

# set C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set project name
project(archichecker)

# all source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# add include directory
target_include_directories(${PROJECT_NAME} PRIVATE "include")


# target platform (WINDOWS, LINUX, MACOS)
set(TARGET_PLATFORM WINDOWS)


# add definitions
add_compile_definitions(${TARGET_PLATFORM} WINDOW_TITLE="${PROJECT_NAME}")