cmake_minimum_required(VERSION 3.8)

project(IllustRay)

add_subdirectory(CPU)

# TODO: Conditionally enable CUDA build
add_subdirectory(GPU)