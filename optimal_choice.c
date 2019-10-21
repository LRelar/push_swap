/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:35:16 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/21 21:12:40 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void	reverse(int com[3][2])
{
    int i;

    i = (com[0][0] == 0) ? 1 : 0;
    if (com[0][i] != 0)
    {
        if (com[0][i] < com[1][i])
        {
            com[1][i] -= com[0][i];
            com[2][i] = com[0][i];
            com[0][i] = 0;
        }
        else
		{
			com[0][i] -= com[1][i];
			com[2][i] = com[1][i];
			com[1][i] = 0;
		}
    }
}

//TODO протестить
static void max_b_to_top(t_dlst *b, t_dlst *max, int com[3][2], int len)
{
	int depth;

	depth = s_hm_skip_b(b, max);

	if (depth <= len / 2)
		com[1][0] = depth;
	else
		com[1][1] = len - depth;
}
//TODO вставка в б  когда элемент не минимум
static void put_in_rpos(t_dlst *b, t_dlst *cur, int com[3][2], int len)
{

}
//TODO не забыть сделать пересчет local и min
static int calc_b(t_frame *fr, t_dlst *cur, int com[3][2])
{
	if (fr->b != NULL)
	{
		if (cur->data < fr->loc_min->data)
		{
			max_b_to_top(fr->b, fr->loc_max, com, fr->LEN_B);
			return (0);
		}

	}
}

void		calc_com1(t_frame *fr)
{
	if (fr->depth1 <= fr->MEDIAN_A)
		fr->com1[0][0] = fr->depth1;
	if (fr->depth1 > fr->MEDIAN_A)
		fr->com1[0][1] = fr->LEN_A - fr->depth1;
	calc_b(fr, fr->com1);
	reverse(fr->com1);
}

void		calc_com2(t_frame *fr)
{
	if (fr->depth2 < fr->MEDIAN_A)
		fr->com2[0][1] = fr->depth2 + 1;
	if (fr->depth2 == fr->MEDIAN_A && (fr->LEN_A % 2 == 0))
		fr->com2[0][0] = fr->depth2 - 1;
	if (fr->depth2 == fr->MEDIAN_A && (fr->LEN_A % 2 == 1))
		fr->com2[0][0] = fr->depth2;
	if (fr->depth2 > fr->MEDIAN_A)
		fr->com2[0][0] = fr->LEN_A - fr->depth2 - 1;
	calc_b(fr, fr->com2);
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
