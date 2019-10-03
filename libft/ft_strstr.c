/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:55:27 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/11/24 18:55:29 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t size_needle;

	size_needle = ft_strlen(needle);
	if (!size_needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
			if (ft_strncmp(haystack, needle, size_needle) == 0)
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
