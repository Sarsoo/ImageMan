# CMakeList.txt : CMake project for ImageMan, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (ImageMan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake" 
                 TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES opencv/4.5.1
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

configure_file(clouds.jpg bin/clouds.jpg COPYONLY)
configure_file(holoshot.png bin/holoshot.png COPYONLY)

# Add source to this project's executable.
add_executable (ImageMan "ImageMan.cpp" "ImageMan.h")
target_link_libraries(ImageMan CONAN_PKG::opencv)
