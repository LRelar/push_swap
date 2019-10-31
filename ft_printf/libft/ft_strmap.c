/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:52:24 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:47:04 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*iter;
	char	*result;

	if (!s)
		return (NULL);
	result = ft_strnew(ft_strlen(s));
	iter = result;
	if (!result)
		return (NULL);
	while (*s)
		*iter++ = (*f)(*s++);
	return (result);
}
