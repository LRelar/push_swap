/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_com_s_ab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:09 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/29 21:42:00 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

void	sa(t_dlst **head_a, int flag)
{
	t_dlst *temp;

	if (((*head_a) != NULL) && (*head_a)->next != (*head_a))
	{
		temp = *head_a;
		(*head_a)->next->prev = (*head_a)->prev;
		(*head_a)->prev->next = (*head_a)->next;
		(*head_a) = (*head_a)->next;
		temp->next = (*head_a)->next;
		temp->prev = *head_a;
		(*head_a)->next->prev = temp;
		(*head_a)->next = temp;
	}
	(flag == 1) ? write(1, "sa\n", 3) : (flag = 0);
}

void	sb(t_dlst **head_b, int flag)
{
	t_dlst *temp;

	if (((*head_b) != NULL) && (*head_b)->next != (*head_b))
	{
		temp = *head_b;
		(*head_b)->next->prev = (*head_b)->prev;
		(*head_b)->prev->next = (*head_b)->next;
		(*head_b) = (*head_b)->next;
		temp->next = (*head_b)->next;
		temp->prev = *head_b;
		(*head_b)->next->prev = temp;
		(*head_b)->next = temp;
	}
	(flag == 1) ? write(1, "sb\n", 3) : (flag = 0);
}

void	s_rep_sa(t_dlst **head_a, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		sa(head_a, 1);
}

void	s_rep_sb(t_dlst **head_b, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		sb(head_b, 1);
}
