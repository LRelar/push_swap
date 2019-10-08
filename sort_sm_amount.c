/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sm_amount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:30 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/08 18:44:25 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../includes/service.h"

void	sort_2(t_frame *fr)
{
	if (fr->a->data > fr->a->next->data)
		sa(&(fr->a));
}

void	sort_3(t_frame *fr)
{
	s_init_tmb(fr);
	if ((fr->top < fr->mid) && (fr->mid > fr->bot) && (fr->bot < fr->top))
		rra(&(fr->a));
	if ((fr->top < fr->mid) && (fr->mid > fr->bot) && (fr->bot > fr->top))
	{
		sa(&(fr->a));
		ra(&(fr->a));
	}
	if ((fr->top > fr->mid) && (fr->mid < fr->bot) && (fr->bot < fr->top))
		ra(&(fr->a));
	if ((fr->top > fr->mid) && (fr->mid < fr->bot) && (fr->bot > fr->top))
		sa(&(fr->a));
	if ((fr->top > fr->mid) && (fr->mid > fr->bot) && (fr->bot < fr->top))
	{
		sa(&(fr->a));
		rra(&(fr->a));
	}
}

void	sort_4(t_frame *fr)
{
	pb(&(fr->a), &(fr->b));
	sort_3(fr);
	fr->temp = (fr->b)->data;
	s_init_tmb(fr);
	if ((fr->temp < fr->top) && (fr->temp < fr->mid) && (fr->temp < fr->bot))
		pa(&(fr->a), &(fr->b));
	if ((fr->temp > fr->top) && (fr->temp < fr->mid) && (fr->temp < fr->bot))
	{
		ra(&(fr->a));
		pa(&(fr->a), &(fr->b));
		rra(&(fr->a));
	}
	if ((fr->temp > fr->top) && (fr->temp > fr->mid) && (fr->temp < fr->bot))
	{
		rra(&(fr->a));
		pa(&(fr->a), &(fr->b));
		s_rep_ra(&(fr->a), 2);
	}
}

void	sort_5(t_frame *fr)
{
	int depth;

	s_rep_pb(&(fr->a), &(fr->b), 2);
	sort_3(fr);
	if (fr->b->data < fr->b->next->data)
		rb(&(fr->b));
	depth = s_hm_skip(fr->a, fr->b->data);
	if (fr->MEDIAN_A > depth)
	{
		s_rep_ra(&(fr->a), depth);
		pa(&(fr->a), &(fr->b));
		pa(&(fr->a), &(fr->b));
		s_rep_rra(&(fr->a), depth + 2);
	}
	else
	{
		s_rep_rra(&(fr->a), fr->LEN_A - depth);
		pa(&(fr->a), &(fr->b));
		pa(&(fr->a), &(fr->b));
		s_rep_ra(&(fr->a), fr->LEN_A - depth + 2);
	}
}