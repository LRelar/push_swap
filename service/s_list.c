#include "../includes/dc_lists.h"

t_dlst	*cr_lists(int *arr, int n)
{
	t_dlst		*first;
	t_dlst		*tmp;
	t_dlst		*new;
	int			i;

	i = 0;
	first = (t_dlst*)malloc(sizeof(t_dlst));
	first->data = arr[i];
	tmp = first;
	new = (t_dlst*)malloc(sizeof(t_dlst) * n);
	while(++i < n)
	{
		(&new[i - 1])->data = arr[i];
		(&new[i - 1])->prev = tmp;
		(&new[i - 1])->next = (&new[i]);
		tmp->prev = (&new[i - 1]);
		if (i == 1)
			tmp->next = (&new[i - 1]);
		tmp = (&new[i - 1]);
	}
	first->prev = tmp;
	tmp->next = first;
	return(first);
}