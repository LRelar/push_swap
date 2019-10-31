/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:25:55 by ekedge-w          #+#    #+#             */
/*   Updated: 2018/12/04 17:53:28 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	qs_helper(int *arr, int mid, int *left, int *right)
{
	while ((arr[*right] >= mid) && (*left < *right))
		(*right)--;
	if (*left != *right)
	{
		arr[*left] = arr[*right];
		(*left)++;
	}
	while ((arr[*left] <= mid) && (*left < *right))
		(*left)++;
	if (*left != *right)
	{
		arr[*right] = arr[*left];
		(*right)--;
	}
}

void		ft_qsort_i(int *arr, int left, int right)
{
	int mid;
	int left_h;
	int right_h;

	right_h = right;
	left_h = left;
	mid = arr[left];
	while (left < right)
		qs_helper(arr, mid, &left, &right);
	arr[left] = mid;
	mid = left;
	left = left_h;
	right = right_h;
	if (left < mid)
		ft_qsort_i(arr, left, mid - 1);
	if (right > mid)
		ft_qsort_i(arr, mid + 1, right);
}
