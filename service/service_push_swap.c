/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:42:05 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/11 21:17:38 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_len_b(t_frame *fr)
{
	t_dlst *temp;

	if (fr->b != NULL)
	{
		fr->LEN_B++;
		temp = fr->b->next;
		while (temp != fr->b)
		{
			fr->LEN_B++;
			temp = temp->next;
		}
	}
}

int		s_hm_skip(t_dlst *head, int val)
{
	int		i;
	t_dlst	*temp;

	i = 0;
	temp = head;
	if (!temp)
		return (i);
	while ((temp->next != head) && (val < temp->data))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	s_split_chunks(t_frame *fr)
{
	int n;
	int div;
	int temp;
	int mod;
	int i;

	i = 0;
	n = (fr->LEN_A > 100) ? 11 : 5;
	div = (fr->MAX - fr->MIN) / n;
	mod = (fr->MAX - fr->MIN) % n;
	temp = fr->MIN;
	while (--n >= 0)
	{
		fr->stages[i++] = temp;
		temp = temp + div;
		if (n == 0)
			fr->stages[i++] = fr->MAX;
		else
			fr->stages[i++] = temp;
		temp++;
	}
}

int		s_min(int *arr, int len)
{
	int i;
	int min;

	i = 0;
	min = arr[0];
	while (++i < len)
		if (arr[i] < min)
			min = arr[i];
	return (min);
}

int		s_max(int *arr, int len)
{
	int i;
	int max;

	i = 0;
	max = arr[0];
	while (++i < len)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}
