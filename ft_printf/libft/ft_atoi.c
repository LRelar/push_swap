/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:01:59 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/11/28 14:07:32 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
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
