/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:16:55 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/05 11:29:15 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char c_ch;

	c_ch = (char)ch;
	while ((*str) || (c_ch == '\0'))
	{
		if (*str == c_ch)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
