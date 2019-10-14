/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_mult_call_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:15 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/14 14:16:32 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

void ra(t_dlst **head_a, int flag)
{
	*head_a = (*head_a)->next;
	(flag == 1) ? write(1, "ra\n", 3) : (flag = 0);
}

void rb(t_dlst **head_b, int flag)
{
	*head_b = (*head_b)->next;
	(flag == 1) ? write(1, "rb\n", 3) : (flag = 0);}

void s_rep_ra(t_dlst **head_a, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		ra(head_a, 1);
}

void s_rep_rb(t_dlst **head_b, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		rb(head_b, 1);
}
