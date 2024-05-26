find_package(Omikuji REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main Omikuji::drawing)
