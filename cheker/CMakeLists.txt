set(SOURCE_C
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
        cheker.c
       )
set(HEADERS_C
        ../includes/service.h
        ../includes/dc_lists.h
        ../includes/input.h)

add_executable(cheker ${SOURCE_C} ${HEADERS_C})
target_link_libraries(cheker libft)