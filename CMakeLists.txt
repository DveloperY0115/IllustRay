# CMakeList.txt : CMake project for Illustray, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

project ("IllustRay")

include_directories(Includes)

add_subdirectory(Tests)

# Add source to this project's executable.
add_executable (Illustray "Illustray.cpp" "Illustray.h" "Includes/Vector.hpp" "Includes/Types.hpp")