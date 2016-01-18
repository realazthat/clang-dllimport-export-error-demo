################################################################################
# Top-level CMakeLists.txt file for Crazy Eddie's GUI System
################################################################################
cmake_minimum_required(VERSION 2.8.11)
if (POLICY CMP0017)
    cmake_policy(SET CMP0017 OLD)
endif()

if (POLICY CMP0045)
    cmake_policy(SET CMP0045 OLD)
endif()

if (APPLE AND NOT CMAKE_OSX_ARCHITECTURES)
    set( CMAKE_OSX_ARCHITECTURES x86_64 CACHE STRING "Build architectures for Mac OS X")
endif()

# default to Release build (it's what most people will use, except cegui devs)
if (NOT CMAKE_BUILD_TYPE)
    set( CMAKE_BUILD_TYPE Release CACHE STRING "Sets the configuration to build (Release, Debug, etc...)")
endif()

################################################################################
# Start of main Project definitions
################################################################################
project(cegui)



include_directories( ./include )


add_library(baselib SHARED src/baselib.cpp)

target_compile_definitions(baselib PRIVATE -DCEGUIBASE_EXPORTS=1)

add_library(mylib SHARED src/mylib.cpp)
target_link_libraries(mylib baselib)

target_compile_definitions(mylib PRIVATE -DOPENGL_GUIRENDERER_EXPORTS=1)







