# Source files to compile with executable
file(GLOB_RECURSE FRAGMENTATION_SOURCE_FILES *.cpp)

ADD_EXECUTABLE(fragmentation-analyser ${FRAGMENTATION_SOURCE_FILES})
#TARGET_LINK_LIBRARIES(fragmentation-analyser)
