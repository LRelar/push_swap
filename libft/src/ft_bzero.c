/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:22:07 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/05 11:28:27 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stdlibft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *temp_s;

	temp_s = (unsigned char *)s;
	while (n--)
		*temp_s++ = '\0';
}