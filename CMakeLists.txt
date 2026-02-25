cmake_minimum_required(VERSION 3.20)
project(geom CXX)
set(CMAKE_CXX_STANDARD 20)

# Sanitizers no debug — detecta bugs de memória e UB
add_compile_options($<$<CONFIG:Debug>:-fsanitize=address,undefined>)
add_link_options($<$<CONFIG:Debug>:-fsanitize=address,undefined>)

# Importa MathVier via submodule
add_subdirectory(external/MathVier)

# Sua lib de geometria
add_library(geom STATIC
    src/predicates.cpp
    src/primitives2d.cpp
)
target_include_directories(geom PUBLIC include)
target_link_libraries(geom PUBLIC MathVier)  # ← herda os headers do MathVier

# Executável de dev/testes manuais
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE geom)

# Testes
add_subdirectory(external/catch2)
add_executable(geom_tests tests/test_closest_point.cpp)
target_link_libraries(geom_tests PRIVATE geom Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(geom_tests)