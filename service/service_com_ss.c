/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_com_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:33:05 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/11 19:21:39 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

void	ss(t_dlst **head_a, t_dlst **head_b)
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
	write(1, "ss\n", 3);
}

void	s_rep_ss(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		ss(head_a, head_b);
}
