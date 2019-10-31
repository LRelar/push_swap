/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_com_p_ab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:22:08 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/31 19:39:39 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

static void	for_norme(t_dlst **temp, t_dlst **head)
{
	(*temp)->next = (*head);
	(*temp)->prev = (*head)->prev;
	(*head)->prev->next = *temp;
	(*head)->prev = *temp;
}

void		pa(t_dlst **head_a, t_dlst **head_b, int flag)
{
	t_dlst *temp;

	if ((head_b != NULL) && (*head_b != NULL))
	{
		temp = *head_b;
		if ((*head_b) == (*head_b)->next)
			*head_b = NULL;
		else
		{
			(*head_b)->next->prev = (*head_b)->prev;
			(*head_b)->prev->next = (*head_b)->next;
			(*head_b) = (*head_b)->next;
		}
		if (*head_a == NULL)
		{
			temp->next = temp;
			temp->prev = temp;
		}
		else
			for_norme(&temp, head_a);
		*head_a = temp;
	}
	(flag == 1) ? write(1, "pa\n", 3) : (flag = 0);
}

void		pb(t_dlst **head_a, t_dlst **head_b, int flag)
{
	t_dlst *temp;

	if ((head_a != NULL) && (*head_a != NULL))
	{
		temp = *head_a;
		if ((*head_a) == (*head_a)->next)
			*head_a = NULL;
		else
		{
			(*head_a)->next->prev = (*head_a)->prev;
			(*head_a)->prev->next = (*head_a)->next;
			(*head_a) = (*head_a)->next;
		}
		if (*head_b == NULL)
		{
			temp->next = temp;
			temp->prev = temp;
		}
		else
			for_norme(&temp, head_b);
		*head_b = temp;
	}
	(flag == 1) ? write(1, "pb\n", 3) : (flag = 0);
}

void		s_rep_pa(t_dlst **head_a, t_dlst **head_b, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		pa(head_a, head_b, flag);
}

void		s_rep_pb(t_dlst **head_a, t_dlst **head_b, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		pb(head_a, head_b, flag);
}
