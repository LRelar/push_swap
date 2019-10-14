/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_com_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:22:08 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/14 14:16:32 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

void pa(t_dlst **head_a, t_dlst **head_b, int flag)
{
	t_dlst *temp;

	if ((head_b != NULL) && (*head_b != NULL))
	{
		temp = *head_b;
		(*head_b)->next->prev = (*head_b)->prev;
		(*head_b)->prev->next = (*head_b)->next;
		(*head_b) = (*head_b)->next;
		if (*head_b == NULL)
		{
			temp->next = temp;
			temp->prev = temp;
		}
		else
		{
			temp->next = (*head_a);
			temp->prev = (*head_a)->prev;
			(*head_a)->prev->next = temp;
			(*head_a)->prev = temp;
		}
		*head_a = temp;
	}
	(flag == 1) ? write(1, "pa\n", 3) : (flag = 0);
}

void pb(t_dlst **head_a, t_dlst **head_b, int flag)
{
	t_dlst *temp;

	if ((head_a != NULL) && (*head_a != NULL))
	{
		temp = *head_a;
		(*head_a)->next->prev = (*head_a)->prev;
		(*head_a)->prev->next = (*head_a)->next;
		(*head_a) = (*head_a)->next;
		if (*head_b == NULL)
		{
			temp->next = temp;
			temp->prev = temp;
		}
		else
		{
			temp->next = (*head_b);
			temp->prev = (*head_b)->prev;
			(*head_b)->prev->next = temp;
			(*head_b)->prev = temp;
		}
		*head_b = temp;
	}
	(flag == 1) ? write(1, "pb\n", 3) : (flag = 0);
}

void s_rep_pa(t_dlst **head_a, t_dlst **head_b, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		pa(head_a, head_b, 1);
}

void s_rep_pb(t_dlst **head_a, t_dlst **head_b, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		pb(head_a, head_b, 1);
}
