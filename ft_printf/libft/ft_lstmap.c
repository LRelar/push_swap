/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:30:09 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/01 18:42:04 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*temp;
	t_list		*temp_list;

	if (!lst || !f || !(*f))
		return (NULL);
	temp_list = f(lst);
	temp = temp_list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp_list->next = f(lst)))
		{
			free(temp_list->next);
			return (NULL);
		}
		temp_list = temp_list->next;
	}
	return (temp);
}
