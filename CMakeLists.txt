cmake_minimum_required(VERSION 3.2)
project(RayEngine)

# Variables.
# 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(BIN_NAME "app")

# Add debugging option.
#
option(DEV_DEBUG "Enter debug mode" 0)
if (DEV_DEBUG)
  add_definitions(-DDEV_DEBUG)
endif()

# Find all source files.
# 
file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Find raylib library.
# 
find_package(raylib 4 REQUIRED)

# Set the project include directories.
# 
include_directories(${INCLUDE_DIRS})

# Create the final binary.
# 
add_executable(${BIN_NAME} main.cpp ${SRC_FILES})

# Link in any libraies the binary needs.
# 
target_link_libraries(${BIN_NAME} raylib)
