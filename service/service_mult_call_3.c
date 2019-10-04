#include "../includes/service.h"

void	s_rep_rra(t_dlst **head_a, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rra(head_a);
}

void	s_rep_rrb(t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rrb(head_b);
}

void	s_rep_rrr(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rrr(head_a, head_b);
}

