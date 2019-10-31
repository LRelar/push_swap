/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_com_rrr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:36:47 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/31 19:41:31 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/service.h"

void	rrr(t_dlst **head_a, t_dlst **head_b, int flag)
{
	*head_a = (*head_a)->prev;
	*head_b = (*head_b)->prev;
	(flag == 1) ? write(1, "rrr\n", 4) : (flag = 0);
}

void	s_rep_rrr(t_dlst **head_a, t_dlst **head_b, int n, int flag)
{
	int i;

	i = -1;
	while (++i < n)
		rrr(head_a, head_b, flag);
}
