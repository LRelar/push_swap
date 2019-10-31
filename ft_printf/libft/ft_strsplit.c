/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:36:13 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/05 13:49:51 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (*str++ == c)
		len++;
	while (*str != c && *str++ != '\0')
		len++;
	return (len);
}

static	size_t	ft_strcntwords(char const *str, char c)
{
	size_t res;

	if (!str)
		return (-1);
	res = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != c && *str != '\0')
			res++;
		while (*str != c && *str != '\0')
			str++;
	}
	return (res);
}

static	void	*ft_str2del(char **str, int i)
{
	while (--i >= 0)
		free(str[i]);
	free(str);
	return (NULL);
}

char			**ft_strsplit(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**strres;
	int		words;

	words = ft_strcntwords(str, c);
	if ((words + 1) == 0 ||
	!(strres = (char **)malloc(sizeof(*strres) * (words + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < words)
	{
		k = 0;
		if (!(strres[i] = ft_strnew(ft_wordlen(&str[j], c) + 1)))
			return (ft_str2del(strres, i));
		while (str[j] == c)
			j++;
		while (str[j] != c && str[j])
			strres[i][k++] = str[j++];
		strres[i][k] = '\0';
	}
	strres[i] = 0;
	return (strres);
}
