
#include "../../Desktop/push21.09/includes/push_swap.h"
#include "../../Desktop/push21.09/includes/service.h"
#include "../../Desktop/push21.09/includes/input.h"

void	exec_command(char *buf, t_dlst **stack_a, t_dlst **stack_b)
{
	if (ft_strequ(buf, "sa"))
		sa(stack_a, 0);
	else if (ft_strequ(buf, "sb"))
		sb(stack_b, 0);
	else if (ft_strequ(buf, "ss"))
		ss(stack_a, stack_b, 0);
	else if (ft_strequ(buf, "ra"))
		ra(stack_a, 0);
	else if (ft_strequ(buf, "rb"))
		rb(stack_b, 0);
	else if (ft_strequ(buf, "rr"))
		rr(stack_a, stack_b, 0);
	else if (ft_strequ(buf, "rra"))
		rra(stack_a, 0);
	else if (ft_strequ(buf, "rrb"))
		rrb(stack_b, 0);
	else if (ft_strequ(buf, "rrr"))
		rrr(stack_a, stack_b, 0);
	else if (ft_strequ(buf, "pa"))
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


long	*ch_parser(int ac, char **av, int i)
{
	long		*arr;
	int			j;

	j = -1;
	arr = (long *)malloc(sizeof(long) * ac);
	while (++i < ac && av[i])
	{
		if (av[i] && (l_atoi(av[i]) >= INT_MIN && l_atoi(av[i]) <= INT_MAX))
			arr[++j] = l_atoi(av[i]);
		else if (!av[i] || l_atoi(av[i]) < INT_MIN || l_atoi(av[i]) > INT_MAX)
			free_and_exit(arr, NULL, NULL, 1);
	}
	if (find_double(arr, ac - 1))
		free_and_exit(arr, NULL, NULL, 1);
	return (arr);
}

int		finish_check(t_dlst *stack_a, t_dlst *stack_b)
{
	t_dlst		*temp;

	if (stack_a != NULL)
	{
		temp = stack_a->next;
		while (temp != stack_a)
		{
			if (!(temp->prev->data < temp->data))
				return (0);
			temp = temp->next;
		}
	}
	if (stack_b)
		return (0);
	return (1);
}

t_dlst	*ch_one_ac_stack(char **av)
{
	char		**cp_one_ac;
	int			count;
	char		**one_ac;
	long		*arr;
	t_dlst		*stack_a;

	count = 0;
	stack_a = NULL;
	one_ac = ft_strsplit(av[1], ' ');
	cp_one_ac = one_ac;
	while (*cp_one_ac++)
		count++;
	if (!ch_digit_cheker(one_ac, -1))
	{
		ft_strdel(one_ac);
		free_and_exit(NULL, NULL, NULL, 1);
	}
	arr = ch_parser(count, one_ac, -1);
	stack_a = s_create_lists(arr, count);
	return (stack_a);
}

int		ch_checker_collector(int ac, char **av)
{
	long		*arr;
	t_dlst		*stack_a;
	t_dlst		*stack_b;
	int			i;

	stack_b = NULL;
	stack_a = NULL;
	i = 0;
	if (ac == 2)
		stack_a = ch_one_ac_stack(av);
	if (ac > 2)
	{
		if (!ch_digit_cheker(av, 0))
			free_and_exit(NULL, NULL, NULL, 1);
		arr = ch_parser(ac - 1, av, 0);
		stack_a = s_create_lists(arr, ac - 1);
	}
	if (stack_a)
		grab_stdout(&stack_a, &stack_b, &i);
	if (!finish_check(stack_a, stack_b))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
    if (ac == 1)
    {
        write(1, "Послушай, дружок, чего-то не хватает.\n\tПодкинь немного аргументов.\n\tА флагом -v можешь включить визуализацию, но только в самом push_swap\n\tВсего доброго\n", 160);
		return (0);
    }
	ch_checker_collector(ac, av) ? ft_putstr("OK\n") : ft_putstr("KO\n");
	return (0);
}