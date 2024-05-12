add_library(affine affine.cpp)
target_include_directories(affine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(affine PUBLIC myproject_compiler_flags)

add_library(fern fern.cpp)
target_include_directories(fern INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(fern PUBLIC myproject_compiler_flags)

find_package(JlCxx)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)

message(STATUS "Found JlCxx at ${JlCxx_location}")
message(STATUS "Julia_LIBRARY at ${Julia_LIBRARY}")

add_library(jl_affine SHARED jl_affine.cpp)
target_link_libraries(jl_affine affine JlCxx::cxxwrap_julia ${Julia_LIBRARY})

add_library(jl_fern SHARED jl_fern.cpp)
target_link_libraries(jl_fern fern JlCxx::cxxwrap_julia ${Julia_LIBRARY})
