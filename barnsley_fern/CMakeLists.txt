cmake_minimum_required(VERSION 3.19)
project(BarnsleyFern)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
if (BUILD_SHARED_LIBS)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

add_library(myproject_compiler_flags INTERFACE)
target_compile_features(myproject_compiler_flags INTERFACE cxx_std_11)

add_subdirectory(src) # affine fern

add_executable(BarnsleyFern main.cpp)
target_link_libraries(BarnsleyFern PUBLIC
                      affine
                      fern
                      myproject_compiler_flags
                      )
