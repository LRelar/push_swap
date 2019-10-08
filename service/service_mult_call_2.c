#include "../includes/push_swap.h"
#include "../includes/service.h"

void	s_rep_ra(t_dlst **head_a, int n)
{
	int i;

	i = -1;
	while (++i < n)
		ra(head_a);
}

void	s_rep_rb(t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rb(head_b);
}

void	s_rep_rr(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rr(head_a, head_b);
}
