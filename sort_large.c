/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:23:22 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/09 21:01:16 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void	do_com1(t_frame *fr)
{
	if (fr->scroll1 == 0)
	{
		s_rep_ra(&(fr->a),fr->com1[0][0]);
		s_rep_rb(&(fr->b),fr->com1[0][0]);

	}

}

static void	do_com2(t_frame *fr)
{

}

void		sort_100_ch1(t_frame *fr, int st_min, int st_max)
{
	s_update_fr(fr);
	search_fs(fr, st_min, st_max);
	calc_com_table(fr);
	(choice_opt(fr) == 1) ? do_com1(fr) : do_com2(fr);
}
void		sort_100(t_frame *fr)
{
	s_split_chunks(fr);
	sort_100_ch1(fr);
}

