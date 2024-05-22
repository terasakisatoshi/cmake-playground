cmake_minimum_required(VERSION 3.19)
project(BarnsleyFern VERSION 1.0)

set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_library(myproject_compiler_flags INTERFACE)
target_compile_features(myproject_compiler_flags INTERFACE cxx_std_17)

add_subdirectory(src) # affine fern

add_executable(main main.cpp)
target_link_libraries(main PUBLIC
                      affine
                      fern
                      myproject_compiler_flags
                      )

install(TARGETS main DESTINATION bin)
install(EXPORT BarnsleyFernTargets
  FILE BarnsleyFernTargets.cmake
  DESTINATION lib/cmake/BarnsleyFern
)

include(CMakePackageConfigHelpers)

# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/BarnsleyFernConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/BarnsleyFern"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/BarnsleyFernConfigVersion.cmake"
  VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/BarnsleyFernConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/BarnsleyFernConfigVersion.cmake
  DESTINATION lib/cmake/BarnsleyFern
  )

export(EXPORT BarnsleyFernTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/BarnsleyFernTargets.cmake"
)
