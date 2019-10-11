#include "../includes/push_swap.h"
#include "./includes/service.h"

void	parser(int ac, char **av)
{
	t_frame 	*fr;
	int			i;
	int			*arr;

	i = 0;
	fr = s_create_frame(NULL, ac - 1, INT_MAX);
	arr = (int *)malloc(sizeof(int) * ac);
	while (++i < ac)
	{
		if (ft_atoi(av[i])) //пока хз как правильно забайтить переполнение
		{
			arr[i - 1] = ft_atoi(av[i]);
			if (fr->MIN > arr[i - 1])
				fr->MIN = arr[i - 1];
		}
		else
			free_and_exit(arr, fr);
	}
	if (!find_double(arr, fr))
		free_and_exit(arr, fr);
	s_create_lists(arr, fr->LEN_A); // надо бы добавить проверку на повторение чисел, но не хватает строчек
}

void	free_and_exit(void *arr, void *fr)
{
	s_del_frame(fr);
	free(arr);
	write(1, "ERROR\n", 7);
	exit(0);
}

int		find_double(int *arr, t_frame *fr)
{
	int i;
	int j;

	i = -1;
	while (++i <= ((fr->LEN_A / 2) + 1))
	{
		j = i;
		while (j++ <= fr->LEN_A)
			if (arr[i] == arr[j])
				return (0);
	}
	return (1);
}

int		digit_cheker(char **av)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (av[++i])
	{
		while (av[i][++j])
			if (av[i][j] != '-' && av[i][j] != '+' && \
					(av[i][j] < '0' || av[i][j] > '9'))
				return (0);
		j = -1;
	}
	return (1);
}