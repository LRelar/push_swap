set(SOURCE_PS
        ../service/service_com_s_ab.c
        ../service/service_push_swap.c
        ../service/service_com_r_ab.c
        ../service/service_com_rr_ab.c
        ../service/service_frame.c
        ../service/service_list.c
        ../service/service_com_p_ab.c
        ../service/service_com_ss.c
        ../service/service_com_rr.c
        ../service/service_com_rrr.c
        ../service/service_push_swap_2.c
        ../service/service_input.c
        ../input.c
        main.c
        sort_small.c
        sort_large.c
        optimal_choice.c)
set(HEADERS_PS
        ../includes/service.h
        ../includes/dc_lists.h
        ../includes/input.h)

add_executable(push_swap ${SOURCE_PS} ${HEADERS_PS})
target_link_libraries(push_swap libft)