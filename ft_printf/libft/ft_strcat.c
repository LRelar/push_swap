/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:28:14 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:15:58 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char *temp;

	temp = dst;
	while (*temp != '\0')
		temp++;
	while (*src != '\0')
		*temp++ = *src++;
	*temp = '\0';
	return (dst);
}
