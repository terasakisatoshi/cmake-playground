add_library(affine affine.cpp)
target_include_directories(affine 
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
	)
target_link_libraries(affine PUBLIC myproject_compiler_flags)

add_library(fern fern.cpp)
target_include_directories(fern 
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
	)
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

set(installable_libs affine fern jl_affine jl_fern myproject_compiler_flags)
install(TARGETS ${installable_libs} 
		EXPORT BarnsleyFernTargets
		DESTINATION lib)
install(FILES affine.hpp fern.hpp DESTINATION include)
