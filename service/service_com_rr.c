/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_com_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:35:20 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/14 14:29:40 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

void rr(t_dlst **head_a, t_dlst **head_b, int flag)
{
	*head_a = (*head_a)->next;
	*head_b = (*head_b)->next;
	(flag == 1) ? write(1, "rr\n", 3) : (flag = 0);
}

void s_rep_rr(t_dlst **head_a, t_dlst **head_b, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		rr(head_a, head_b, 1);
}
