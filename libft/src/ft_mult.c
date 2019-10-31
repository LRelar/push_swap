/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:10:32 by sstark            #+#    #+#             */
/*   Updated: 2019/09/18 16:10:43 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stdlibft.h"

static void	sum(char *arr, char *arr2, int n)
{
	while (n-- > 0)
	{
		arr[n] = arr[n] + arr2[n];
		if (arr[n] > 9)
		{
			arr[n] = arr[n] - 10;
			arr[n - 1]++;
		}
	}
}

void		ft_mult(char a[2000], char b[2000], char arr[4000])
{
	int			j;
	char		h_a[2001];
	int const	c = 2000;

	ft_bzero(arr, c * 2);
	j = c;
	while (j-- > 0)
	{
		ft_mult_atod(a, b[j], h_a, c);
		sum(arr + j, h_a, c + 1);
	}
}
