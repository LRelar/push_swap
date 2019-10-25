/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:11:01 by sstark            #+#    #+#             */
/*   Updated: 2019/10/25 21:11:07 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		del(void *content, size_t size)
{
	if (content)
	{
		ft_bzero(content, size);
		size = 0;
		free(content);
	}
}
