/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_for_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:10:50 by sstark            #+#    #+#             */
/*   Updated: 2019/09/18 16:11:09 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

void		ft_power_for_two(int power, char rez[2000])
{
	char *a;
	char *c;

	a = malloc(2000);
	c = malloc(2000);
	ft_bzero(c, 2000);
	c[1999] = 1;
	while (power > 0)
	{
		if (power > 2)
		{
			power -= 3;
			ft_mult_atod(c, 8, a, 2000);
		}
		else
		{
			power--;
			ft_mult_atod(c, 2, a, 2000);
		}
		swap(&a, &c);
	}
	ft_memcpy(rez, c, 2000);
	free(a);
	free(c);
}
