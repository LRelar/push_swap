/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:05:36 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/11/28 19:13:55 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	left;
	size_t	right;
	size_t	len;

	if (!s)
		return (NULL);
	left = 0;
	len = ft_strlen(s);
	if (!len)
		return (ft_strnew(len));
	while (*(s + left) && (*(s + left) == ' ' || *(s + left) == '\n' ||
	*(s + left) == '\t'))
		left++;
	if (left == len)
		return (ft_strnew(len));
	right = len - 1;
	while ((s + right) != (s + left) && (*(s + right) == ' '
	|| *(s + right) == '\n' || *(s + right) == '\t'))
		right--;
	return (ft_strsub(s, left, right - left + 1));
}
