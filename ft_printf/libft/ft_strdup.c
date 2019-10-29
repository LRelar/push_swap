/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:28:53 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:31:16 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*temp;
	size_t		size;

	size = ft_strlen(s);
	temp = (char *)malloc(size + 1);
	if (temp)
	{
		while (*s != '\0')
			*temp++ = *s++;
		*temp = '\0';
	}
	return (temp ? temp - size : temp);
}
