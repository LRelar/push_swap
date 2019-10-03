/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:28:38 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:26:04 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *temp;

	temp = dst;
	while ((n--) && (*src != '\0'))
		*temp++ = *src++;
	if (++n != 0)
		while (n--)
			*temp++ = '\0';
	return (dst);
}
