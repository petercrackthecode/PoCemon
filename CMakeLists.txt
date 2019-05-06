cmake_minimum_required(VERSION 3.0.0)
project(PoCemon VERSION 0.1.0)

include(CTest)
enable_testing()

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2 COMPONENTS graphics)


include_directories("${CMAKE_SOURCE_DIR}")
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PoCemon)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


add_subdirectory(src)

set_property(TARGET PoCemon PROPERTY CXX_STANDARD 11)
