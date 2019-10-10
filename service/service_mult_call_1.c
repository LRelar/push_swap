/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_mult_call_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:09 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/09 17:13:29 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	s_rep_sa(t_dlst **head_a, int n)
{
	int i;

	i = -1;
	while (++i < n)
		sa(head_a);
}

void	s_rep_sb(t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		sb(head_b);
}

void	s_rep_ss(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		ss(head_a, head_b);
}

void	s_rep_pa(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		pa(head_a,head_b);
}

void	s_rep_pb(t_dlst **head_a, t_dlst **head_b, int n)
{
	int i;

	i = -1;
	while (++i < n)
		pb(head_a, head_b);
}
