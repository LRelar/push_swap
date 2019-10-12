cmake_minimum_required(VERSION 3.13)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories(libft include)

set(SOURCE_EXE main.c sort_small.c service/service_com_s_ab.c
        includes/service.h service/service_push_swap.c service/service_com_r_ab.c
        service/service_com_rr_ab.c service/service_frame.c optimal_choice.c
        sort_large.c includes/dc_lists.h service/service_list.c
        service/service_com_p_ab.c service/service_com_ss.c service/service_com_rr.c service/service_com_rrr.c service/service_push_swap_2.c)

add_executable(test ${SOURCE_EXE} includes/push_swap.h)

add_subdirectory(libft)

target_link_libraries(test libft)