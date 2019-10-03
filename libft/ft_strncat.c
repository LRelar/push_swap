/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:31:49 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:25:50 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char *temp;

	temp = dst;
	while (*temp != '\0')
		temp++;
	while ((n--) && (*src != '\0'))
		*temp++ = *src++;
	*temp = '\0';
	return (dst);
}
