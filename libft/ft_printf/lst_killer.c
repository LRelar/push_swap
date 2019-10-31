/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_killer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:31:50 by sstark            #+#    #+#             */
/*   Updated: 2019/09/18 16:32:03 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	del_one(t_list **lst)
{
	free((*lst)->content);
	ft_memset(*lst, 0, sizeof(t_list));
	ft_memdel((void **)lst);
}

void		del_lst(t_list **lst, int from_end, int ex)
{
	t_list	*b;
	t_list	*a;
	t_list	*c;
	int		i;

	if ((i = ft_lstlen(*lst)) < from_end)
		exit_pf(*lst, 1);
	a = *lst;
	while (--i - from_end && a)
		a = a->next;
	b = a;
	c = a->next;
	a = c;
	while (a)
	{
		a = a->next;
		if (--i != ex)
			del_one(&c);
		else
		{
			b->next = c;
			c->next = NULL;
		}
		c = a;
	}
}

void		del_win(t_list **lst, void *content)
{
	t_list	*a;
	t_list	*b;

	a = *lst;
	if (a->content == content)
	{
		*lst = a->next;
		ft_memdel((void **)&a);
		return ;
	}
	b = a;
	a = a->next;
	while (a)
	{
		if (a->content == content)
		{
			b->next = a->next;
			del_one(&a);
			return ;
		}
		b = a;
		a = a->next;
	}
}

void		exit_pf(t_list *lst, int code)
{
	t_list	*b;

	b = lst;
	while (lst)
	{
		lst = lst->next;
		del_one(&b);
		b = lst;
	}
	if (code)
		exit(code);
}

void		*sm(void *content, t_list **lst, int code)
{
	t_list	*new;
	t_list	*cpy;

	if (content == NULL)
		exit_pf(*lst, 1);
	if (!(new = ft_lstnew(NULL, 0)))
		exit_pf(*lst, 1);
	if (*lst == NULL)
		*lst = new;
	else
	{
		cpy = *lst;
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = new;
	}
	new->content = content;
	new->content_size = code;
	return (content);
}
