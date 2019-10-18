/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:06:03 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/14 15:10:53 by ekedge-w         ###   ########.fr       */
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
		printf("%d ", lst->data);
		temp = lst->next;
		while (temp != lst)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}

static void		show_both_hlp(t_dlst *b)
{
	t_dlst *temp;

	if (b != NULL)
	{
		printf("%22d\n", b->data);
		temp = b->next;
		while (temp != b)
		{
			printf("%22d\n", temp->data);
			temp = temp->next;
		}
	}
}


//TODO на основе этого сделать полноценный модуль визуализации
int			s_show_both_list(t_dlst *a, t_dlst *b)
{
    t_dlst *temp1;
    t_dlst *temp2;

    if (a == NULL && b == NULL)
		return  (0);
   // sleep(1);
	//printf("%c[2J%c[H", 27, 27);
    printf("________________________\nStack A:\tStack B:\n________________________\n");
    if (b == NULL)
		s_show_list_v(a);
	if (a == NULL)
		show_both_hlp(b);
	if (a != NULL && b != NULL)
	{
		printf("%-11d%11d\n", a->data, b->data);
		temp1 = a->next;
		temp2 = b->next;
		while (temp1 != a || temp2 != b )
		{
			if (temp1 != a && temp2 != b)
			{
				printf("%-11d%11d\n", temp1->data, temp2->data);
				temp1 = temp1->next;
				temp2 = temp2->next;
				continue;
			}
			if (temp1 == a && temp2 != b)
			{
				printf("%22d\n",temp2->data);
				temp2 = temp2->next;;
				continue;
			}
			if (temp1 != a && temp2 == b)
			{
				printf("%-11d\n", temp1->data);
				temp1 = temp1->next;
				continue;
			}
		}
	}
	return (printf("________________________\n"));
}