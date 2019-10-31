/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:38:16 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:12:58 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;
	unsigned char	temp_c;

	temp_b = (unsigned char *)b;
	temp_c = (unsigned char)c;
	while (len--)
		*temp_b++ = temp_c;
	return (b);
}
