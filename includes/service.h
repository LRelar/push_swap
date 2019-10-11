/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:42:35 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/11 18:25:53 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SERVICE_H
#define PUSH_SWAP_SERVICE_H

#include "push_swap.h"

/*********************commands**********************/

void	sa(t_dlst **head_a);
void	sb(t_dlst **head_b);
void	ss(t_dlst **head_a, t_dlst **head_b);

void	ra(t_dlst **head_a);
void	rb(t_dlst **head_b);
void	rr(t_dlst **head_a, t_dlst **head_b);

void	rra(t_dlst **head_a);
void	rrb(t_dlst **head_b);
void	rrr(t_dlst **head_a, t_dlst **head_b);

void	pa(t_dlst **head_a, t_dlst **head_b);
void	pb(t_dlst **head_a, t_dlst **head_b);

/*********************mult call*********************/

void	s_rep_sa(t_dlst **head_a, int n);
void	s_rep_sb(t_dlst **head_b, int n);
void	s_rep_ss(t_dlst **head_a, t_dlst **head_b, int n);

void	s_rep_ra(t_dlst **head_a, int n);
void	s_rep_rb(t_dlst **head_b, int n);
void	s_rep_rr(t_dlst **head_a, t_dlst **head_b, int n);

void	s_rep_rra(t_dlst **head_a, int n);
void	s_rep_rrb(t_dlst **head_b, int n);
void	s_rep_rrr(t_dlst **head_a, t_dlst **head_b, int n);

void 	s_rep_pa(t_dlst **head_a, t_dlst **head_b, int n);
void	s_rep_pb(t_dlst **head_a, t_dlst **head_b, int n);

/********************frame***************************/

t_frame *s_create_frame(int *arr, int len, int min);
t_frame	*s_del_frame(t_frame *frame);
void	s_update_fr(t_frame *fr);

/********************push swap***********************/

int		s_hm_skip(t_dlst *head, int val);
void	s_split_chunks(t_frame *fr);
void	s_len_b(t_frame *fr);

/********************input***********************/

void	free_and_exit(void *arr, void *vol);
int		find_double(int *arr, t_frame *vol);
int		digit_cheker(char **av);
void	parser(int ac, char **av);

#endif //PUSH_SWAP_SERVICE_H
