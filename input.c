#include "includes/input.h"

int	*ch_parser(int ac, char **av, int i, int *len)
{
	int		*arr;
	int			j;

	j = -1;
	arr = (int *)malloc(sizeof(int) * ac - 1);
	while (++i < ac)
	{
		if (av[i] && (l_atoi(av[i]) >= INT_MIN && l_atoi(av[i]) <= INT_MAX))
			arr[++j] = ft_atoi(av[i]);
		else
			free_and_exit(arr, NULL, NULL, 1);
	}
	if (find_double(arr, ac - 1))
		free_and_exit(arr, NULL, NULL, 1);
	*len = j + 1;
	return (arr);
}
int	*one_ac_stack(char **av, int *len)
{
	char		**cp_one_ac;
	int			count;
	char		**one_ac;
	int		*arr;

	count = 0;
	one_ac = ft_strsplit(av[1], ' ');
	cp_one_ac = one_ac;
	while (*cp_one_ac++)
		count++;
	if (!ch_digit_cheker(one_ac, -1))
	{
		ft_strdel(one_ac);
		free_and_exit(NULL, NULL, NULL, 1);
	}
	arr = ch_parser(count, one_ac, -1, len);
	return (arr);
}

int *checker_collector(int ac, char **av, int *len)
{
	int		*arr;
	int			i;

	arr = NULL;
	i = 0;
	if (ac == 2)
		arr = one_ac_stack(av,len);
	if (ac > 2)
	{
		if (!ch_digit_cheker(av, 0))
			free_and_exit(NULL, NULL, NULL, 1);
		arr = ch_parser(ac, av, 0, len);
	}
	return (arr);
}
