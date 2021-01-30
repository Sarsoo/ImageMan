# CMakeList.txt : CMake project for ImageMan, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.7...3.19)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(ImageMan VERSION 1.0 DESCRIPTION "Playing with conan package manager and OpenCV" LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

# ImageMan Target
add_executable (ImageMan src/ImageMan.cpp)
target_link_libraries(ImageMan CONAN_PKG::opencv)

target_include_directories(ImageMan
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

#set_property(TARGET ImageMan PROPERTY CXX_STANDARD 17)
target_compile_features(ImageMan PRIVATE cxx_std_17)
