cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories(libft include)

set(SOURCE_EXE main.c)

add_executable(test ${SOURCE_EXE})

add_subdirectory(libft)

target_link_libraries(test libft)