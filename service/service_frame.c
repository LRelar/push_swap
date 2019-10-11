/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_in_cr_frame.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:01 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/09 18:21:32 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void		null_all_int(t_frame *fr)
{
	fr->MIN = 0;
	fr->LEN_A = 0;
	fr->LEN_B = 0;
	fr->MEDIAN_A = 0;
	fr->MEDIAN_B = 0;
	fr->temp = 0;
	fr->top = 0;
	fr->mid = 0;
	fr->bot = 0;
	fr->scroll1 = 0;
	fr->scroll2 = 0;
	while (fr->depth1 < 3)
	{
		while (fr->depth2 < 2)
		{
			fr->com1[fr->depth1][fr->depth2] = 0;
			fr->com2[fr->depth1][fr->depth2] = 0;
			fr->depth2++;
		}
		fr->depth1++;
	}
	fr->depth1 = 0;
	fr->depth2 = 0;
}

void			s_len_b(t_frame *fr)
{
	t_dlst *temp;

	temp = fr->b;
	while (temp != fr->b)
	{
		fr->LEN_B++;
		temp = temp->next;
	}
}

void			s_update_fr(t_frame *fr)
{
	t_dlst *temp;

	null_all_int(fr);
	temp = fr->a;
	while (temp != fr->a)
	{
		fr->LEN_A++;
		temp = temp->next;
	}
	s_len_b(fr);
	fr->MEDIAN_A = fr->LEN_A / 2;
	fr->MEDIAN_B = fr->LEN_B / 2;
}

void			s_init_tmb(t_frame *fr)
{
	fr->top = fr->a->data;
	fr->mid = fr->a->next->data;
	fr->bot = fr->a->prev->data;
}
 //TODO если возвращает 0 - аборт программы ? надо ли это?
t_frame			*s_create_frame(t_dlst *a, t_dlst *b, int len, int min)
{
	t_frame *fr;

	fr = (t_frame *)malloc(sizeof(t_frame));
	if (len > 5)
	{
		fr->stages = (int *)malloc(sizeof(int) * ((len <= 100) ? 10 : 22));
		if (fr->stages == NULL)
			return (s_delete_frame(fr));
	}
	else
		fr->stages = NULL;
	null_all_int(fr);
	fr->a = a;
	fr->b = b;
	fr->MIN = min;
	fr->LEN_A = len;
	fr->MEDIAN_A = len / 2;
	return (fr);
}

t_frame			*s_delete_frame(t_frame *frame)
{
	if (frame != NULL)
	{
		del_lst(frame->a);
		del_lst(frame->a);
		if (frame->stages != NULL)
			free(frame->stages);
	}
	return (NULL);
}
