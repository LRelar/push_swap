/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:37:09 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:38:28 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	iter;
	size_t	size_s;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	sub = ft_strnew(len);
	if (!sub)
		return (NULL);
	iter = start;
	while (iter < size_s && len--)
	{
		*(sub + iter - start) = *(s + iter);
		iter++;
	}
	return (sub);
}
