/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:31:27 by sstark            #+#    #+#             */
/*   Updated: 2019/10/31 19:18:25 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_charinstr(const char *str, char c)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == c)
			return (1);
	return (0);
}

int			search_size(short int size[5])
{
	int i;

	i = -1;
	while (++i < 5)
		if (size[i])
			return (1);
	return (0);
}
