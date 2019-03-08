# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("PoCemon")
add_executable (PoCemon "main.cpp" "PoCemon.cpp" "PoCemonData.cpp" "Combat.cpp")

# Include sub-projects.
#add_subdirectory ("PoCemon")
