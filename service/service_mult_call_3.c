/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_mult_call_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:18 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/10 19:06:17 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

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

void	s_rep_rrr(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rrr(head_a, head_b);
}

