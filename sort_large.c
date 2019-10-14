/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:23:22 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/14 14:16:32 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void	do_com(t_dlst **a, t_dlst **b, int scroll, int com[3][2])
{
	if (scroll == 0)
	{
		s_rep_ra(a, com[0][0], 1);
		s_rep_rb(b, com[1][0], 1);
		s_rep_rr(a, b, com[2][0], 1);
		pb(a, b, 1);
		s_rep_rra(a, com[0][1], 1);
		s_rep_rrb(b, com[1][1], 1);
		s_rep_rrr(a, b, com[2][1], 1);
	}
	else
	{
		s_rep_rra(a, com[0][1], 1);
		s_rep_rrb(b, com[1][1], 1);
		s_rep_rrr(a, b, com[2][1], 1);
		pb(a, b, 1);
		s_rep_ra(a, com[0][0], 1);
		s_rep_rb(b, com[1][0], 1);
		s_rep_rr(a, b, com[2][0], 1);
	}
}

void		sort_chunk(t_frame *fr, int st_min, int st_max)
{
	while (1)
	{
		s_update_fr(fr);
		search_fs(fr, st_min, st_max);
		if (fr->fst == NULL && fr->sec == NULL)
			break;
		calc_com_table(fr);
		(choice_opt(fr) == 1) ? do_com(&(fr->a), &(fr->b), fr->scroll1, fr->com1) :
		do_com(&(fr->a), &(fr->b), fr->scroll2, fr->com2);
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
		i++;
	}
	s_len_b(fr);
	s_rep_pa(&(fr->a), &(fr->b), fr->LEN_B, 1);
}

