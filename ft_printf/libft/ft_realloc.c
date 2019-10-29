/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:41:26 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/06 14:37:02 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void *new_ptr;

	if (!new_size)
	{
		ft_free(ptr);
		return (NULL);
	}
	new_ptr = ft_malloc(new_size);
	if (!ptr)
		return (new_ptr);
	ft_memcpy(new_ptr, ptr, ft_allocated_size(new_ptr));
	ft_free(ptr);
	return (new_ptr);
}
