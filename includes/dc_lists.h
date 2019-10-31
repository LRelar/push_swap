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

#endif //PUSH_SWAP_DC_LISTS_H
