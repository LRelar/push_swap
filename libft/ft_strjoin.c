/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:05:36 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:31:53 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*pocket;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(pocket = ft_strnew(s1_len + s2_len)))
		return (NULL);
	ft_memcpy((void *)pocket, (const void *)s1, s1_len);
	ft_memcpy((void *)pocket + s1_len, (const void *)s2, s2_len);
	return (pocket);
}
