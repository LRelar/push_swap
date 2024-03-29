/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_push_swap_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:46:35 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/29 21:44:43 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_len_a(t_frame *fr)
{
	t_dlst *temp;

	fr->LEN_A = 0;
	if (fr->a != NULL)
	{
		fr->LEN_A++;
		temp = fr->a->next;
		while (temp != fr->a)
		{
			fr->LEN_A++;
			temp = temp->next;
		}
	}
}

void	s_len_b(t_frame *fr)
{
	t_dlst *temp;

	fr->LEN_B = 0;
	if (fr->b != NULL)
	{
		fr->LEN_B++;
		temp = fr->b->next;
		while (temp != fr->b)
		{
			fr->LEN_B++;
			temp = temp->next;
		}
	}
}

int		s_hm_skip_a(t_dlst *head, int val)
{
	int		i;
	t_dlst	*temp;

	i = 0;
	temp = head;
	if (!temp)
		return (i);
	if (val > temp->data)
		i++;
	temp = head->next;
	while ((temp != head) && (val > temp->data))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int		s_search_max(t_dlst *head, t_dlst *max)
{
	int		i;
	t_dlst	*temp;

	i = 0;
	temp = head;
	if (!temp)
		return (i);
	if (max->data != temp->data)
		i++;
	temp = head->next;
	while (max->data != temp->data)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int		s_hm_skip_b(t_dlst *head, int val)
{
	int		i;
	t_dlst	*temp;

	i = 0;
	temp = head;
	if (!temp)
		return (i);
	if (val < temp->data)
		i++;
	temp = head->next;
	while ((temp != head) && (val < temp->data))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
