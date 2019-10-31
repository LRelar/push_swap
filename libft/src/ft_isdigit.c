/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:09:28 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:09:20 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stdlibft.h"

int		ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	return (0);
}