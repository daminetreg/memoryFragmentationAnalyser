cmake_minimum_required (VERSION 2.6)
project (fragmentationAnalyser)

# Build Type
SET(CMAKE_BUILD_TYPE debug)

# Enable Tests
INCLUDE (CTest)

# Versionning
set (licenseSystem_VERSION_MAJOR 0)
set (licenseSytem_VERSION_MINOR 10)

# Pass our settings to the Software
configure_file (
    "${PROJECT_SOURCE_DIR}/src/fragmentation.hpp.in"
    "${PROJECT_BINARY_DIR}/fragmentation.hpp"
)

# Include the configured file
include_directories ("${PROJECT_BINARY_DIR}")

# Configure boost for this Project
find_package(Boost REQUIRED) 
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

# Define Executable Output Directory
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Include our configuration header
include_directories(${CMAKE_SOURCE_DIR}/src)

# Build the different applications
add_subdirectory (src)

# Build test source files
#add_subdirectory (tests)
