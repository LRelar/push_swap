/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:43:23 by sstark            #+#    #+#             */
/*   Updated: 2019/10/29 21:43:26 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/input.h"

long	l_atoi(const char *nptr)
{
	long long	result;
	short int	sign;

	result = 0;
	sign = 1;
	while (*nptr == '\n' || *nptr == '\t' || *nptr == '\r' || *nptr == '\v'
											|| *nptr == '\f' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr++ - '0');
		if (result < 0)
		{
			if (sign < 0)
				return (0);
			else
				return (-1);
		}
	}
	return (result * sign);
}

int		ch_digit_cheker(char **my_av, int i)
{
	int			j;

	j = -1;
	if (!(my_av[i + 1]))
		return (0);
	while (my_av[++i])
	{
		while (my_av[i][++j])
		{
			if ((my_av[i][j] < '0' || my_av[i][j] > '9') \
							&& my_av[i][j] != '-' && my_av[i][j] != '+')
				return (0);
			if ((my_av[i][j] == '-' || my_av[i][j] == '+') \
					&& (my_av[i][j + 1] < '0' || my_av[i][j + 1] > '9'))
				return (0);
		}
		j = -1;
	}
	return (1);
}

int		find_double(int *arr, int ac)
{
	int			i;
	int			j;

	i = -1;
	while (++i <= ((ac / 2) + 1))
	{
		j = i;
		while (j <= ac - 1)
		{
			j++;
			if (arr[i] == arr[j])
				return (1);
		}
	}
	return (0);
}

void	free_and_exit(void *arr, t_dlst *a, t_dlst *b, int flag)
{
	if (a)
		s_del_lst(a);
	if (b)
		s_del_lst(b);
	if (arr)
		free(arr);
	if (flag)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}
