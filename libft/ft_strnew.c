/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:26:15 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:44:05 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;

	if ((size + 1) == 0)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * ++size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, size);
	return (temp);
}
