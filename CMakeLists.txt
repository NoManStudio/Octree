cmake_minimum_required(VERSION 3.10)

project(octree)
add_compile_options(-g)

set(CMAKE_CXX_STANDARD 17)

# Set source files
set(SOURCES
        main.cpp
        )

# Header files
set(HEADERS
        Octree.h
        OctNode.h
        )

# Add executable
add_executable(octree ${SOURCES})
# Link libraries if needed
# target_link_libraries(octree)

# Include headers in build
target_include_directories(octree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)