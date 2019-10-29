/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:22:14 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/04 18:38:12 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	ft_sqrt(long l)
{
	long		temp;
	long		div;
	unsigned	res;

	div = l;
	res = (unsigned)l;
	if (l <= 0)
		return (0);
	while (1)
	{
		temp = l / div + div;
		div = temp >> 1;
		div += temp & 1;
		if (res > div)
			res = (unsigned)div;
		else
		{
			if (l / res == res - 1 && l % res == 0)
				res--;
			return (res);
		}
	}
}
