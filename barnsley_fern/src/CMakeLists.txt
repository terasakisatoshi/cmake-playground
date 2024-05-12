add_library(affine affine.cpp)
target_include_directories(affine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(affine PUBLIC myproject_compiler_flags)
set_target_properties(affine PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS})

add_library(fern fern.cpp)
target_include_directories(fern INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(fern PUBLIC myproject_compiler_flags)
set_target_properties(fern PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS})
