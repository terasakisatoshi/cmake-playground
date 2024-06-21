cmake_minimum_required(VERSION 3.15)
project(cxxwrap2)
# https://github.com/JuliaInterop/libcxxwrap-julia/blob/main/CMakeLists.txt
# https://github.com/JuliaInterop/libcxxwrap-julia/blob/main/testlib-builder/src/testlib/CMakeLists.txt
find_package(JlCxx)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)

add_library(hello SHARED hello.cpp)

message("-- AAA" ${Julia_LIBRARY})
message(STATUS "Found JlCxx at ${JlCxx_location}")
message("-- BBB" ${JLCXX_TARGET} JlCxx::cxxwrap_julia)

target_link_libraries(hello JlCxx::cxxwrap_julia)
