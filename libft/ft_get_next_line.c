/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:26:25 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/18 11:52:31 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		line_copy(char **line, char *content, char c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

static t_list	*get_file(int fd, t_list **file_list)
{
	t_list	*temp;

	if (!file_list)
		return (NULL);
	temp = *file_list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("", fd);
	ft_lstadd(file_list, temp);
	return (temp);
}

static int		reading(const int fd, char **content)
{
	int		read_result;
	char	*temp;
	char	buf[BUFF_SIZE + 1];

	while ((read_result = read(fd, buf, BUFF_SIZE)))
	{
		buf[read_result] = '\0';
		temp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(temp);
		if (ft_strchr(buf, ENDL))
			break ;
	}
	return (read_result);
}

int				ft_get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			read_result;
	static t_list	*file_list;
	t_list			*cur_file;
	char			*temp;

	if (fd < 0 || !line || (read(fd, buf, 0)) < 0 ||
			(!(cur_file = get_file(fd, &file_list))))
		return (-1);
	temp = cur_file->content;
	read_result = reading(fd, &temp);
	cur_file->content = temp;
	if (!read_result && !*temp)
		return (0);
	read_result = line_copy(line, cur_file->content, ENDL);
	temp = cur_file->content;
	if (temp[read_result] != '\0')
	{
		cur_file->content = ft_strdup(&((cur_file->content)[read_result + 1]));
		free(temp);
	}
	else
		temp[0] = '\0';
	return (1);
}
