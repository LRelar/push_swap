/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:15:30 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/11/30 20:05:46 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_memsize(int n)
{
	int		res;
	long	temp_n;

	temp_n = (long)n;
	res = 0;
	if (temp_n < 0)
	{
		temp_n *= -1;
		res++;
	}
	while ((temp_n /= 10) > 0)
		res++;
	return (++res);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		size;
	long	temp_n;

	temp_n = n;
	size = ft_memsize(n);
	if (!(s = ft_strnew(size)))
		return (NULL);
	if (temp_n < 0)
	{
		temp_n *= -1;
		s[0] = '-';
	}
	while (--size > 0)
	{
		s[size] = (temp_n % 10) + '0';
		temp_n /= 10;
	}
	if (n >= 0)
		s[size] = temp_n + '0';
	return (s);
}
