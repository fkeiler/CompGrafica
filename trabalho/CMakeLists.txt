cmake_minimum_required(VERSION 3.15)
project(trabalho)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_executable(trabalho main.cpp Coordinate.cpp Coordinate.hpp Cylinder.cpp Cylinder.hpp Ray.cpp Ray.hpp Plane.cpp Plane.hpp Result.cpp Result.hpp Sphere.cpp Sphere.hpp CG.hpp Camera.cpp Camera.hpp)
target_link_libraries(trabalho -lglut -lGL -lGLU)