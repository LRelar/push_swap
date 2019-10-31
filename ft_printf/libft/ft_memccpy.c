/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:22:07 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:48:16 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*temp_dst;
	unsigned char		*temp_src;
	unsigned char		temp_c;

	temp_c = (unsigned char)c;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (n--)
	{
		*temp_dst = *temp_src;
		if ((*temp_src) == temp_c)
			return (++temp_dst);
		temp_dst++;
		temp_src++;
	}
	return (NULL);
}
