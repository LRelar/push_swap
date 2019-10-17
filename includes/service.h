/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:42:35 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/15 17:24:05 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SERVICE_H
#define PUSH_SWAP_SERVICE_H

#include "push_swap.h"

/*********************commands**********************/

void	sa(t_dlst **head_a, int flag);
void	sb(t_dlst **head_b, int flag);
void	ss(t_dlst **head_a, t_dlst **head_b, int flag);

void	ra(t_dlst **head_a, int flag);
void	rb(t_dlst **head_b, int flag);
void	rr(t_dlst **head_a, t_dlst **head_b, int flag);

void	rra(t_dlst **head_a, int flag);
void	rrb(t_dlst **head_b, int flag);
void	rrr(t_dlst **head_a, t_dlst **head_b, int flag);

void	pa(t_dlst **head_a, t_dlst **head_b, int flag);
void	pb(t_dlst **head_a, t_dlst **head_b, int flag);

/*********************mult call*********************/

void s_rep_sa(t_dlst **head_a, int n, int flag);
void s_rep_sb(t_dlst **head_b, int n, int flag);
void s_rep_ss(t_dlst **head_a, t_dlst **head_b, int n, int flag);

void s_rep_ra(t_dlst **head_a, int n, int flag);
void s_rep_rb(t_dlst **head_b, int n, int flag);
void s_rep_rr(t_dlst **head_a, t_dlst **head_b, int n, int flag);

void s_rep_rra(t_dlst **head_a, int n, int flag);
void s_rep_rrb(t_dlst **head_b, int n, int flag);
void s_rep_rrr(t_dlst **head_a, t_dlst **head_b, int n, int flag);

void s_rep_pa(t_dlst **head_a, t_dlst **head_b, int n, int flag);
void s_rep_pb(t_dlst **head_a, t_dlst **head_b, int n, int flag);

/********************frame***************************/

t_frame	*s_create_frame(int *arr, int len, int min, int max);
t_frame	*s_del_frame(t_frame *frame);
void	s_update_fr(t_frame *fr);

/********************push swap 1***********************/
void	s_init_tmb(t_frame *fr);
void	s_split_chunks(t_frame *fr);
int 	s_min(int *arr, int len);
int 	s_max(int *arr, int len);
int		s_check(int *a, int len);
/********************push swap 2***********************/

int		s_hm_skip_b(t_dlst *head, int val);
int		s_hm_skip_a(t_dlst *head, int val);
void	s_len_a(t_frame *fr);
void	s_len_b(t_frame *fr);

#endif //PUSH_SWAP_SERVICE_H
