/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:22:07 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:13:32 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*temp_dst;
	char	*temp_src;

	temp_dst = (char *)dst;
	temp_src = (char *)src;
	if (temp_src < temp_dst)
		while ((int)(--n) >= 0)
			*(temp_dst + n) = *(temp_src + n);
	else
		while (n--)
			*temp_dst++ = *temp_src++;
	return (dst);
}
