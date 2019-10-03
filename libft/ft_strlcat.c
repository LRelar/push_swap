/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:36:55 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/06 14:40:25 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	d = dst;
	s = src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n != 0)
	{
		while ((*s != '\0') && (--n >= 1))
		{
			*d++ = *s++;
		}
		*d = '\0';
	}
	return ((dlen > size ? size : dlen) + ft_strlen(src));
}
