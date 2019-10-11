/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_mult_call_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:15 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/11 17:36:01 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

void	ra(t_dlst **head_a)
{
	*head_a = (*head_a)->next;
	write(1, "ra\n", 3);
}

void	rb(t_dlst **head_b)
{
	*head_b = (*head_b)->next;
	write(1, "rb\n", 3);
}

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
