#include "../includes/push_swap.h"
#include "../includes/input.h"
#include "../includes/service.h"
#include "../includes/cheker.h"

void	exec_command(char *buf, t_dlst **stack_a, t_dlst **stack_b)
{
	if (ft_strequ(buf, "sa"))
		sa(stack_a, 0);
	else if (ft_strequ(buf, "sb") && *stack_b)
		sb(stack_b, 0);
	else if (ft_strequ(buf, "ss") && *stack_b)
		ss(stack_a, stack_b, 0);
	else if (ft_strequ(buf, "ra"))
		ra(stack_a, 0);
	else if (ft_strequ(buf, "rb") && *stack_b)
		rb(stack_b, 0);
	else if (ft_strequ(buf, "rr") && *stack_b)
		rr(stack_a, stack_b, 0);
	else if (ft_strequ(buf, "rra"))
		rra(stack_a, 0);
	else if (ft_strequ(buf, "rrb") && *stack_b)
		rrb(stack_b, 0);
	else if (ft_strequ(buf, "rrr") && *stack_b)
		rrr(stack_a, stack_b, 0);
	else if (ft_strequ(buf, "pa") && *stack_b)
		pa(stack_a, stack_b, 0);
	else if (ft_strequ(buf, "pb"))
		pb(stack_a, stack_b, 0);
	else
		free_and_exit(buf, NULL, NULL, 1);
}

void	grab_stdout(t_dlst **stack_a, t_dlst **stack_b, int *i)
{
	char		*buf;
	int			rez;

	while ((rez = ft_get_next_line(0, &buf)) > 0)
	{
		i++;
		exec_command(buf, stack_a, stack_b);
	}
}
