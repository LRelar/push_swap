/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_com_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:22:08 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/11 19:13:14 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

void	pa(t_dlst **a, t_dlst **b)
{
	t_dlst *temp;

	if ((b != NULL) && (*b != NULL))
	{
		temp = *b;
		(*b)->next->prev = (*b)->prev;
		(*b)->prev->next = (*b)->next;
		(*b) = (*b)->next;
		if (*b == NULL)
		{
			temp->next = temp;
			temp->prev = temp;
		}
		else
		{
			temp->next = (*a);
			temp->prev = (*a)->prev;
			(*a)->prev->next = temp;
			(*a)->prev = temp;
		}
		*a = temp;
	}
	write(1, "pa\n", 3);
}

void	pb(t_dlst **a, t_dlst **b)
{
	t_dlst *temp;

	if ((a != NULL) && (*a != NULL))
	{
		temp = *a;
		(*a)->next->prev = (*a)->prev;
		(*a)->prev->next = (*a)->next;
		(*a) = (*a)->next;
		if (*b == NULL)
		{
			temp->next = temp;
			temp->prev = temp;
		}
		else
		{
			temp->next = (*b);
			temp->prev = (*b)->prev;
			(*b)->prev->next = temp;
			(*b)->prev = temp;
		}
		*b = temp;
	}
	write(1, "pb\n", 3);
}

void	s_rep_pa(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		pa(head_a, head_b);
}

void	s_rep_pb(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		pb(head_a, head_b);
}
