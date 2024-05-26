add_library(drawing drawing.cpp)

target_include_directories(drawing
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )
target_link_libraries(drawing PUBLIC ${PROJECT_NAME}_compiler_flags)

set_property(TARGET drawing PROPERTY VERSION "0.1.0")
set_property(TARGET drawing PROPERTY SOVERSION "0.1.0")

set(installable_libs drawing ${PROJECT_NAME}_compiler_flags)
install(TARGETS ${installable_libs}
	EXPORT ${PROJECT_NAME}Targets
	DESTINATION lib)

install(FILES drawing.hpp DESTINATION include)
