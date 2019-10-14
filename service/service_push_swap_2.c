/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_push_swap_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:46:35 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/14 13:39:40 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_len_a(t_frame *fr)
{
	t_dlst *temp;

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
	while ((temp!= head) && (val > temp->data))
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
	while ((temp->next != head) && (val < temp->data))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}