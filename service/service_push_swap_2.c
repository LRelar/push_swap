/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_push_swap_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:46:35 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/12 16:48:33 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		s_hm_skip_a(t_dlst *head, int val)
{
	int		i;
	t_dlst	*temp;

	i = 0;
	temp = head;
	if (!temp)
		return (i);
	if (val > temp->data)
		i++;
	temp = head->next;
	while ((temp!= head) && (val > temp->data))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
