cmake_minimum_required(VERSION 3.0.0)
project(PoCemon VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable (PoCemon "main.cpp" "PoCemon.cpp" "PoCemonData.cpp" "Combat.cpp" "testTay.cpp" "testAman.cpp" "testPeter.cpp" "testKate.cpp")
include_directories("${CMAKE_SOURCE_DIR}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_property(TARGET PoCemon PROPERTY CXX_STANDARD 11)