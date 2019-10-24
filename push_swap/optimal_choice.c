/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:35:16 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/24 20:31:59 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void	reverse(int com[4][2])
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

static int put_max_min(t_frame *fr, t_dlst *cur, int com[4][2])
{
	t_dlst	*temp;
	int 	depth;

	depth = 0;
	temp = fr->b;
	if (temp != fr->loc_max)
	{
		depth++;
		temp = temp->next;
		while (temp != fr->loc_max)
		{
			depth++;
			temp = temp->next;
		}
	}
	if (depth == 1)
		com[3][1] = 1;
	else
	{
		if (depth <= fr->MEDIAN_B)
			com[1][0] = depth;
		else
			com[1][1] = fr->LEN_B - depth;
	}
	return (0);
}


static int put_in_rpos(t_frame *fr, t_dlst *cur, int com[4][2])
{
	t_dlst	*t1;
	t_dlst	*t2;
	int		depth;

	depth = 0;
	t1 = fr->b->prev;
	t2 = t1->next;
	if (!(t1->data > cur->data && cur->data > t2->data))
	{
		depth++;
		t1 = t1->next;
		t2 = t2->next;
		while ((t1 != fr->b->prev) && (!(t1->data > cur->data && cur->data > t2->data)))
		{
			depth++;
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	if (depth == 1)
		com[3][1] = 1;
	else
	{
		if (depth <= fr->MEDIAN_B)
			com[1][0] = depth;
		else
			com[1][1] = fr->LEN_B - depth;
	}
	return (0);
}

static int calc_b(t_frame *fr, t_dlst *cur, int com[4][2])
{
	if (fr->b != NULL)
	{
		if ((cur->data < fr->loc_min->data) || (cur->data > fr->loc_max->data))
			return (put_max_min(fr, cur, com));
		if (cur->data > fr->loc_min->data && cur->data < fr->loc_max->data)
			return (put_in_rpos(fr, cur, com));
	}
	return (0);
}

void		calc_com1(t_frame *fr)
{
	if (fr->depth1 == 1)
		fr->com1[3][0] = 1;
	else
	{
		if (fr->depth1 <= fr->MEDIAN_A)
			fr->com1[0][0] = fr->depth1;
		if (fr->depth1 > fr->MEDIAN_A)
			fr->com1[0][1] = fr->LEN_A - fr->depth1;
	}
	calc_b(fr, fr->fst, fr->com1);
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
	calc_b(fr,fr->sec, fr->com2);
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
	while (i < 4)
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
