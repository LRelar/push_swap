/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:52:07 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/04 18:35:50 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power(double x, long n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (ft_power((1 / x), (-n)));
	if (n % 2)
		return (x * ft_power(x, (n - 1)));
	return (ft_power((x * x), (n / 2)));
}
