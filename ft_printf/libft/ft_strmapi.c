/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:24:04 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:46:24 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char		*iter;
	char		*result;
	short int	ind;

	if (!s)
		return (NULL);
	result = ft_strnew(ft_strlen(s));
	iter = result;
	ind = 0;
	if (!result)
		return (NULL);
	while (*s)
		*iter++ = (*f)(ind++, *s++);
	return (result);
}
