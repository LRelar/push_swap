/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:35:16 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/15 16:41:34 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void	reverse(int com[3][2])
{
	int j;

	j = (com[0][0] > 0) ? 0 : 1;
	if (com[0][j] < com[1][j])
	{
		com[1][j] -= com[0][j];
		com[2][j] = com[0][j];
		com[0][j] = 0;
	}
	else
	{
		com[0][j] -= com[1][j];
		com[2][j] = com[1][j];
		com[1][j] = 0;
	}
}

static void	calc_b(int depth, int len, int *scroll, int com[3][2])
{
	if (depth <= len / 2)
	{
		com[1][0] = depth;
		com[1][1] = depth;
	}
	else
	{
		com[1][0] = len - depth + 1;
		com[1][1] = len - depth;
		*scroll = 1;
	}
}

void		calc_com1(t_frame *fr)
{
	if (fr->depth1 <= fr->MEDIAN_A)
		fr->com1[0][0] = fr->depth1;
	if (fr->depth1 > fr->MEDIAN_A)
		fr->com1[0][1] = fr->LEN_A - fr->depth1;
	fr->depth1 = s_hm_skip_b(fr->b, fr->fst->data);
	calc_b(fr->depth1, fr->LEN_B, &(fr->scroll1), fr->com1);
	reverse(fr->com1);
}

void		calc_com2(t_frame *fr)
{
	if (fr->depth2 < fr->MEDIAN_A)
		fr->com2[0][1] = fr->depth2 + 1;
	if (fr->depth2 == fr->MEDIAN_A && (fr->depth2 % 2 == 0))
		fr->com2[0][0] = fr->depth2 - 1;
	if (fr->depth2 == fr->MEDIAN_A && (fr->depth2 % 2 == 1))
		fr->com2[0][0] = fr->depth2;
	if (fr->depth2 > fr->MEDIAN_A && (fr->depth2 % 2 == 0))
		fr->com2[0][0] = fr->LEN_A - fr->depth2 - 1;
	if (fr->depth2 > fr->MEDIAN_A && (fr->depth2 % 2 == 1))
	{
		if (fr->MEDIAN_A + 1 == fr->depth2)
			fr->com2[0][0] = fr->LEN_A - fr->depth2;
		else
			fr->com2[0][0] = fr->LEN_A - fr->depth2 - 1;
	}
	calc_b(fr->depth2, fr->LEN_B, &(fr->scroll2), fr->com2);
	reverse(fr->com2);
}

int			choice_opt(t_frame *fr)
{
	int i;
	int j;
	int score;

	i = 0;
	j = 0;
	score = 0;
	while (i < 3)
	{
		while (j < 2)
		{
			score += fr->com1[i][j];
			score -= fr->com2[i][j];
			j++;
		}
		i++;
	}
	if (score < 0)
		return (1);
	else
		return (2);
}
