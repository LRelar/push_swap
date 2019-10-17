/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_in_cr_frame.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:01 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/17 19:21:52 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

static void		null_mass(t_frame *fr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 2)
		{
			fr->com1[i][j] = 0;
			fr->com2[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

static void		null_all_int(t_frame *fr)
{
	fr->MIN = 0;
	fr->MAX = 0;
	fr->LEN_A = 0;
	fr->LEN_B = 0;
	fr->MEDIAN_A = 0;
	fr->MEDIAN_B = 0;
	fr->scroll1 = 0;
	fr->scroll2 = 0;
	fr->depth1 = 0;
	fr->depth2 = 0;
	null_mass(fr);
}

void			s_update_fr(t_frame *fr)
{
	t_dlst *temp;

	null_all_int(fr);
	fr->fst = NULL;
	fr->sec = NULL;
	s_len_a(fr);
	s_len_b(fr);
	fr->MEDIAN_A = fr->LEN_A / 2;
	fr->MEDIAN_B = fr->LEN_B / 2;
}

t_frame			*s_create_frame(int *arr, int len, int min, int max)
{
	t_frame *fr;

	fr = (t_frame *)malloc(sizeof(t_frame));
	if (len > 5)
	{
		fr->stages = (int *)malloc(sizeof(int) * ((len <= 100) ? 10 : 22));
		if (fr->stages == NULL)
			return (s_del_frame(fr));
	}
	else
		fr->stages = NULL;
	null_all_int(fr);
	fr->a = s_create_lists(arr, len);
	fr->b = NULL;
	fr->MIN = min;
	fr->MAX = max;
	fr->LEN_A = len;
	fr->MEDIAN_A = len / 2;
	fr->fst = NULL;
	fr->sec = NULL;
	return (fr);
}

t_frame			*s_del_frame(t_frame *frame)
{
	if (frame != NULL)
	{
		s_del_lst(frame->a);
		s_del_lst(frame->b);
		if (frame->stages != NULL)
			free(frame->stages);
		free(frame);
	}
	return (NULL);
}
