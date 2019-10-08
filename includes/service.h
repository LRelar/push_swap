/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:42:35 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/08 18:42:38 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_SERVICE_H
#define PUSH_SWAP_SERVICE_H

#include "push_swap.h"

/*********************mult call*********************/

/*                ********I********                */

void	s_rep_sa(t_dlst **head_a, int n);
void	s_rep_sb(t_dlst **head_b, int n);
void	s_rep_ss(t_dlst **head_a, t_dlst **head_b, int n);
void 	s_rep_pa(t_dlst **head_a, t_dlst **head_b, int n);
void	s_rep_pb(t_dlst **head_a, t_dlst **head_b, int n);

/*                ********II*******                */

void	s_rep_ra(t_dlst **head_a, int n);
void	s_rep_rb(t_dlst **head_b, int n);
void	s_rep_rr(t_dlst **head_a, t_dlst **head_b, int n);

/*                ********III******                */

void	s_rep_rra(t_dlst **head_a, int n);
void	s_rep_rrb(t_dlst **head_b, int n);
void	s_rep_rrr(t_dlst **head_a, t_dlst **head_b, int n);

/********************frame***************************/

void	s_init_tmb(t_frame *fr);
t_frame	*s_create_frame(t_dlst *a, t_dlst *b, int len, int min, int max);
t_frame	*s_delete_frame(t_frame *frame);

/********************push swap***********************/

int		s_hm_skip(t_dlst *head, int val);
void	s_split_chunks(t_frame *fr);
void	s_search_fs(t_frame *fr, int min, int max);
void	s_calc_com_table(t_frame *fr);

#endif //PUSH_SWAP_SERVICE_H
