#ifndef PUSH_SWAP_SERVICE_H
#define PUSH_SWAP_SERVICE_H

#include "push_swap.h"

void	s_rep_sa(t_dlst **head_a, int n);
void	s_rep_sb(t_dlst **head_b, int n);
void	s_rep_ss(t_dlst **head_a, t_dlst **head_b, int n);
void	s_rep_ra(t_dlst **head_a, int n);
void	s_rep_rb(t_dlst **head_b, int n);
void	s_rep_rra(t_dlst **head_a, int n);
void	s_rep_rrb(t_dlst **head_b, int n);
void	s_rep_rrr(t_dlst **head_a, t_dlst **head_b, int n);
void 	s_rep_pa(t_dlst **head_a, t_dlst **head_b, int n);
void	s_rep_pb(t_dlst **head_a, t_dlst **head_b, int n);

#endif //PUSH_SWAP_SERVICE_H
