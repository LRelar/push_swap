/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:06:03 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/11 17:52:55 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_dlst	*malloc_init_link(t_dlst *head, t_dlst *temp1, int data)
{
	t_dlst	*temp2;

	temp2 = (t_dlst *)malloc(sizeof(t_dlst));
	temp2->next = head;
	temp2->prev = temp1;
	temp2->data = data;
	return (temp2);
}

t_dlst			*s_create_lists(int *arr, int n)
{
	t_dlst	*head;
	t_dlst	*temp1;
	t_dlst	*temp2;
	int		i;

	i = -1;
	head = NULL;
	temp1 = NULL;
	while (++i < n)
	{
		if (head == NULL)
		{
			head = (t_dlst *)malloc(sizeof(t_dlst));
			head->next = head;
			head->prev = head;
			head->data = arr[i];
			temp1 = head;
			continue;
		}
		temp2 = malloc_init_link(head, temp1, arr[i]);
		temp1->next = temp2;
		head->prev = temp2;
		temp1 = temp2;
	}
	return (head);
}

void			s_del_lst(t_dlst *lst)
{
	t_dlst *tail;
	t_dlst *temp;

	if (lst != NULL)
	{
		tail = lst->prev;
		temp = lst;
		while (temp != tail)
		{
			temp = temp->next;
			free(temp->prev);
		}
		free(temp);
	}
}

void			s_show_list_v(t_dlst *lst)
{
	t_dlst *temp;

	if (lst != NULL)
	{
		printf("%d\n", lst->data);
		temp = lst->next;
		while (temp != lst)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
}

void			s_show_list_g(t_dlst *lst)
{
	t_dlst *temp;

	if (lst != NULL)
	{
		printf("%d", lst->data);
		temp = lst->next;
		while (temp != lst)
		{
			printf("% d", temp->data);
			temp = temp->next;
		}
	}
}
