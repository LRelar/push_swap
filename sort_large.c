/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:23:22 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/17 15:00:18 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void	do_com(t_dlst **a, t_dlst **b, int scroll, int com[3][2])
{
    s_rep_ra(a,com[0][0],1);
    s_rep_rra(a,com[0][1],1);
    if (scroll == 0)
    {
        s_rep_rb(b,com[1][0],1);
        s_rep_rr(a,b,com[2][0],1);
        pb(a,b,1);
        s_rep_rrb(b,com[1][1],1);
    }
    else
    {
        s_rep_rrb(b,com[1][1],1);
        s_rep_rrr(a,b,com[2][1],1);
        pb(a,b,1);
        s_rep_rb(b,com[1][0],1);
    }
}
//TODO протестировать прохождения - есть сомнения что он не проскакивает их при четной длинне
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
		if (fr->sec == NULL)
		{
			calc_com1(fr);
			do_com(&(fr->a), &(fr->b), fr->scroll1, fr->com1);
		}
		if (fr->fst == NULL)
		{
			calc_com2(fr);
			do_com(&(fr->a), &(fr->b), fr->scroll2, fr->com2);
		}
		if (fr->fst != NULL && fr->sec != NULL)
		{
			calc_com1(fr);
			calc_com2(fr);
			(choice_opt(fr) == 1) ?
			do_com(&(fr->a), &(fr->b), fr->scroll1, fr->com1) :
			do_com(&(fr->a), &(fr->b), fr->scroll2, fr->com2);
		}
	}
}
void		sort_large(t_frame *fr)
{
	int i;
	int n;

	i = 0;
	n = (fr->LEN_A <= 100) ? 10 : 22;
	s_split_chunks(fr);

	while (i + 1 < n)
	{
		sort_chunk(fr, i, i + 1);
		i += 2;
	}
	s_len_b(fr);
	s_rep_pa(&(fr->a), &(fr->b), fr->LEN_B, 1);
}

