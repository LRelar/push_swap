/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:42:24 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/14 18:16:47 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "dc_lists.h"

typedef struct	s_push_swap_frame
{
    int			MIN;
	int			MAX;
    int			LEN_A;
    int			LEN_B;
    int			MEDIAN_A;
	int			MEDIAN_B;

    t_dlst		*a;
    t_dlst		*b;

    t_dlst		*fst;
    t_dlst		*sec;
	int			depth1;
    int			depth2;
    int			com1[3][2];
	int			com2[3][2];
	int			scroll1;
	int			scroll2;

	int			temp;
	int			top;
	int			mid;
	int			bot;

	int			*stages;
}				t_frame;

void 			sort_2(t_frame *fr);
void			sort_3(t_frame *fr);
void			sort_4(t_frame *fr);
void			sort_5(t_frame *fr);
void			sort_large(t_frame *fr);
void			sort_chunk(t_frame *fr, int st_min, int st_max);
void			search_fs(t_frame *fr, int min, int max);

/********************optimal choice***********************/

void			calc_com1(t_frame *fr);
void			calc_com2(t_frame *fr);
int				choice_opt(t_frame *fr);

#endif //PUSH_SWAP_PUSH_SWAP_H
