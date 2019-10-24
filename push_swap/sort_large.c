/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:23:22 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/22 17:12:35 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void	do_com(t_dlst **a, t_dlst **b, int com[3][2])
{
	s_rep_ra(a,com[0][0],1);
    s_rep_rra(a,com[0][1],1);
    s_rep_rb(b,com[1][0],1);
	s_rep_rrb(b,com[1][1],1);
	s_rep_rr(a,b,com[2][0],1);
	s_rep_rrr(a,b,com[2][1],1);
	pb(a,b,1);
//	s_show_both_list(*a, *b);
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
		if (fr->fst == NULL && fr->sec == NULL)
			break;
		else
		{
			calc_com1(fr);
			calc_com2(fr);
			if (choice_opt(fr) == 1)
			{
				do_com(&(fr->a), &(fr->b), fr->com1);
				if (fr->loc_max == NULL || fr->fst->data > fr->loc_max->data)
					fr->loc_max = fr->fst;
				if (fr->loc_min == NULL || fr->fst->data < fr->loc_min->data)
					fr->loc_min = fr->fst;
			}
			else
			{
				do_com(&(fr->a), &(fr->b), fr->com2);
				if (fr->loc_max == NULL || fr->sec->data > fr->loc_max->data)
					fr->loc_max = fr->sec;
				if (fr->loc_min == NULL || fr->sec->data < fr->loc_min->data)
					fr->loc_min = fr->sec;
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
	int i;
	int n;

	n = (fr->LEN_A <= 100) ? 10 : 22;
	i = n - 1;
	s_split_chunks(fr);

	while (i >= 1)
	{
		sort_chunk(fr, i - 1, i);
		i-=2;
	}
	s_len_b(fr);
	max_on_top(fr);
	s_rep_pa(&(fr->a), &(fr->b), fr->LEN_B, 1);
}

