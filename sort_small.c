/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm_amount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:30 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/14 14:16:32 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void	sort_5_last2(t_frame *fr)
{
	fr->depth1 = s_hm_skip_a(fr->a, fr->b->data);
	if (fr->MEDIAN_A >= fr->depth1)
	{
		s_rep_ra(&(fr->a), fr->depth1, 1);
		pa(&(fr->a), &(fr->b), 1);
		s_rep_rra(&(fr->a), fr->depth1, 1);
	}
	else
	{
		s_rep_rra(&(fr->a), fr->LEN_A - fr->depth1, 1);
		pa(&(fr->a), &(fr->b), 1);
		s_rep_ra(&(fr->a), fr->LEN_A - fr->depth1 + 1, 1);
	}
}

void		sort_2(t_frame *fr)
{
	if (fr->a->data > fr->a->next->data)
		sa(&(fr->a), 1);
}

void		sort_3(t_frame *fr)
{
	s_init_tmb(fr);
	if ((fr->top < fr->mid) && (fr->mid > fr->bot) && (fr->bot < fr->top))
		rra(&(fr->a), 1);
	if ((fr->top < fr->mid) && (fr->mid > fr->bot) && (fr->bot > fr->top))
	{
		sa(&(fr->a), 1);
		ra(&(fr->a), 1);
	}
	if ((fr->top > fr->mid) && (fr->mid < fr->bot) && (fr->bot < fr->top))
		ra(&(fr->a), 1);
	if ((fr->top > fr->mid) && (fr->mid < fr->bot) && (fr->bot > fr->top))
		sa(&(fr->a), 1);
	if ((fr->top > fr->mid) && (fr->mid > fr->bot) && (fr->bot < fr->top))
	{
		sa(&(fr->a), 1);
		rra(&(fr->a), 1);
	}
	s_init_tmb(fr);
}

void		sort_4(t_frame *fr)
{
	pb(&(fr->a), &(fr->b), 1);
	sort_3(fr);
	fr->temp = (fr->b)->data;
	if (fr->temp < fr->top)
		pa(&(fr->a), &(fr->b), 1);
	if ((fr->temp > fr->top) && (fr->temp < fr->mid))
	{
		ra(&(fr->a), 1);
		pa(&(fr->a), &(fr->b), 1);
		rra(&(fr->a), 1);
	}
	if ((fr->temp > fr->mid) && (fr->temp < fr->bot))
	{
		rra(&(fr->a), 1);
		pa(&(fr->a), &(fr->b), 1);
		s_rep_ra(&(fr->a), 2, 1);
	}
	if (fr->temp > fr->bot)
	{
		pa(&(fr->a), &(fr->b), 1);
		ra(&(fr->a), 1);
	}
	fr->b = NULL;
}

void		sort_5(t_frame *fr)
{
	s_rep_pb(&(fr->a), &(fr->b), 2, 1);
	sort_3(fr);
	s_update_fr(fr);
	sort_5_last2(fr);
	s_update_fr(fr);
	sort_5_last2(fr);
	fr->b = NULL;
}
