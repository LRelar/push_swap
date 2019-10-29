/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult_atod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:10:12 by sstark            #+#    #+#             */
/*   Updated: 2019/09/18 16:10:23 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mult_atod(char *arr, int n, char *rez, int count)
{
	int i;

	ft_bzero(rez, count + 1);
	i = count;
	while (i-- > 1)
	{
		rez[i] += arr[i] * n;
		while (rez[i] > 9)
		{
			rez[i] -= 10;
			rez[i - 1] += 1;
		}
	}
}
