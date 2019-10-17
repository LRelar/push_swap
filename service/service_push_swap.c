/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:42:05 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/17 19:21:52 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_init_tmb(t_frame *fr)
{
	fr->top = fr->a->data;
	fr->mid = fr->a->next->data;
	fr->bot = fr->a->prev->data;
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
		temp = temp + div - 1;
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

int s_check(int *a, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return  (1);
}