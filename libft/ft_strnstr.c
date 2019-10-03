/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:34:18 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 19:26:31 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t size_needle;

	size_needle = ft_strlen(needle);
	if (!size_needle)
		return ((char *)haystack);
	while (*haystack && len && (len >= size_needle))
	{
		if (*haystack == *needle)
			if (ft_strncmp(haystack, needle, size_needle) == 0)
				return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
