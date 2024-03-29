/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:23:22 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/30 20:41:56 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"
#include "../includes/visual.h"

static void	do_com(t_frame *fr, int com[4][2])
{
	s_rep_ra(&(fr->a),com[0][0],1);
    s_rep_rra(&(fr->a),com[0][1],1);
    s_rep_rb(&(fr->b),com[1][0],1);
	s_rep_rrb(&(fr->b),com[1][1],1);
	s_rep_rr(&(fr->a),&(fr->b),com[2][0],1);
	s_rep_rrr(&(fr->a),&(fr->b),com[2][1],1);
	s_rep_sa(&(fr->a),com[3][0],1);
	pb(&(fr->a),&(fr->b),1);
	s_rep_sb(&(fr->b),com[3][1],1);
	visualizer(fr);
}

void		search_fs(t_frame *fr, int min, int max)
{
	t_dlst *head;
	t_dlst *tail;

	head = fr->a;
	tail = head->prev;
	while (head != tail)
	{
		if ((fr->fst == NULL) && (head->data >= fr->stages[min]) &&
			(head->data <= fr->stages[max]))
			fr->fst = head;
		if ((fr->sec == NULL) && (tail->data >= fr->stages[min]) &&
			(tail->data <= fr->stages[max]))
			fr->sec = tail;
		if ((fr->fst != NULL) && (fr->sec != NULL))
			break;
		if ((fr->fst == NULL) && (++fr->depth1))
			head = head->next;
		if ((fr->sec == NULL) && (++fr->depth2))
			tail = tail->prev;
		if (head == tail->next)
			break;
	}
	if ((fr->fst == NULL) && (head->data >= fr->stages[min]) &&
		(head->data <= fr->stages[max]))
		fr->fst = head;
	if ((fr->sec == NULL) && (tail->data >= fr->stages[min]) &&
		(tail->data <= fr->stages[max]))
		fr->sec = tail;
}

void		sort_chunk(t_frame *fr, int st_min, int st_max)
{
	while (fr->a != NULL)
	{
		s_update_fr(fr);
		search_fs(fr, st_min, st_max);
		visualizer(fr);
		if (fr->fst == NULL && fr->sec == NULL)
			break;
		else
		{
			calc_com1(fr);
			calc_com2(fr);
			if (choice_opt(fr) == 1)
			{
				if (fr->loc_max == NULL || fr->fst->data > fr->loc_max->data)
					fr->loc_max = fr->fst;
				if (fr->loc_min == NULL || fr->fst->data < fr->loc_min->data)
					fr->loc_min = fr->fst;
				do_com(fr, fr->com1);
			}
			else
			{
				if (fr->loc_max == NULL || fr->sec->data > fr->loc_max->data)
					fr->loc_max = fr->sec;
				if (fr->loc_min == NULL || fr->sec->data < fr->loc_min->data)
					fr->loc_min = fr->sec;
				do_com(fr, fr->com2);
			}
		}
	}
}
static	void max_on_top(t_frame *fr)
{
	int		depth;
	t_dlst	*temp;

	depth = 0;
	temp = fr->b;
	if (fr->loc_max != temp)
		depth++;
	temp = temp->next;
	while (fr->loc_max != temp)
	{
		depth++;
		temp = temp->next;
	}
	if (depth <= fr->MEDIAN_B)
		s_rep_rb(&(fr->b), depth, 1);
	else
		s_rep_rrb(&(fr->b), fr->LEN_B - depth, 1);
}

void		sort_large(t_frame *fr)
{
	int n;

	n = (fr->LEN_A <= 100) ? 14 : 26;
	fr->i = n - 1;
	s_split_chunks(fr);

	while (fr->i >= 1)
	{
		sort_chunk(fr, fr->i - 1, fr->i);
		fr->i-=2;
	}
	s_len_b(fr);
	max_on_top(fr);
	s_rep_pa(&(fr->a), &(fr->b), fr->LEN_B, 1);
}