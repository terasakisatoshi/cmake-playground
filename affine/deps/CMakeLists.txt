cmake_minimum_required(VERSION 3.24)
project(main)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

find_package(Eigen3 REQUIRED)
find_package(JlCxx)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)
message(STATUS "Found JlCxx at ${JlCxx_location}")
message(STATUS "Julia_LIBRARY at ${Julia_LIBRARY}")

add_library(jl_affine SHARED jl_affine.cpp)
target_link_libraries(jl_affine affine JlCxx::cxxwrap_julia ${Julia_LIBRARY})

include_directories(${EIGEN3_INCLUDE_DIR})

add_library(myproject_compiler_flags INTERFACE)

add_library(affine affine.cpp)
target_compile_features(myproject_compiler_flags INTERFACE cxx_std_17)

target_include_directories(affine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(affine PUBLIC myproject_compiler_flags)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE affine myproject_compiler_flags)

enable_testing()

add_subdirectory(test)
