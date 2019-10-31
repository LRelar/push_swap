/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:13:38 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/05 17:15:33 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stdlibft.h"

void	*ft_malloc(size_t s)
{
	size_t *ret;

	ret = malloc(sizeof(size_t) + s);
	*ret = s;
	return (&ret[1]);
}