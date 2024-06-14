find_package(JlCxx)
find_package(Eigen3)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)

add_library(hello SHARED hello.cpp)

message(STATUS "Found JlCxx at ${JlCxx_location}")

target_link_libraries(hello JlCxx::cxxwrap_julia JlCxx::cxxwrap_julia_stl ${Julia_LIBRARY} Eigen3::Eigen)
