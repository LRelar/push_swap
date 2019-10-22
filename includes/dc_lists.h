#ifndef PUSH_SWAP_DC_LISTS_H
#define PUSH_SWAP_DC_LISTS_H

#include <stdlib.h>

typedef struct					s_double_link_lst
{
	int						    data;
	struct s_double_link_lst	*next;
	struct s_double_link_lst	*prev;
}								t_dlst;


t_dlst							*s_create_lists(int *arr, int n);
void							s_del_lst(t_dlst *lst);
void							s_show_list_v(t_dlst *lst);
void							s_show_list_g(t_dlst *lst);
int								s_show_both_list(t_dlst *a, t_dlst *b);


#endif //PUSH_SWAP_DC_LISTS_H
