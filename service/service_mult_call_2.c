/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_mult_call_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:15 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/09 17:13:29 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	s_rep_ra(t_dlst **head_a, int n)
{
	int i;

	i = -1;
	while (++i < n)
		ra(head_a);
}

void	s_rep_rb(t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rb(head_b);
}

void	s_rep_rr(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		rr(head_a, head_b);
}
