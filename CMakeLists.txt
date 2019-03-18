cmake_minimum_required(VERSION 3.0.0)
project(PoCemon VERSION 0.1.0)

include(CTest)
enable_testing()

<<<<<<< HEAD
add_executable (PoCemon "main.cpp" "PoCemon.cpp" "PoCemonData.cpp" "Combat.cpp" "testTay.cpp" "testAman.cpp" "testPeter.cpp" "testKate.cpp")
include_directories("${CMAKE_SOURCE_DIR}")
=======
add_executable (PoCemon "main.cpp" "PoCemon.cpp" "PoCemon.h" "PoCemonData.cpp" "PoCemonData.h" "Combat.cpp" "Combat.h" "Enums.h" "testTay.cpp" "testAman.cpp" "testPeter.cpp" "testKate.cpp" "Ability.cpp" "Ability.h" "AttackStd.cpp" "AttackStd.h")
include_directories("${CMAKE_SOURCE_DIR}")
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PoCemon)
>>>>>>> 715ca8e7d67d3f02e313e4636252527cc330a23c

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_property(TARGET PoCemon PROPERTY CXX_STANDARD 11)