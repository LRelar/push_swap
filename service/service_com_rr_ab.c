/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_mult_call_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:18 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/11 17:37:18 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

void	rra(t_dlst **head_a)
{
	*head_a = (*head_a)->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_dlst **head_b)
{
	*head_b = (*head_b)->prev;
	write(1, "rrb\n", 4);
}

void	s_rep_rra(t_dlst **head_a, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rra(head_a);
}

void	s_rep_rrb(t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rrb(head_b);
}
