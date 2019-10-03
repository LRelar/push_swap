/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:43:50 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:38:45 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	c_ch;
	char	*result;

	c_ch = (char)ch;
	result = NULL;
	while (*str)
	{
		if (*str == c_ch)
			result = (char *)str;
		str++;
	}
	if (*str == c_ch)
		result = (char *)str;
	return (result);
}
