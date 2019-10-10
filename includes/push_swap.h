/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:42:24 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/09 19:24:12 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <stdlib.h>

typedef struct	s_double_link_lst
{
    int							data;
    struct s_double_link_lst	*next;
    struct s_double_link_lst	*prev;
}				t_dlst;

void sa(t_dlst **head_a);
void sb(t_dlst **head_b);
void ss(t_dlst **head_a, t_dlst **head_b);

void ra(t_dlst **head_a);
void rb(t_dlst **head_b);
void rr(t_dlst **head_a, t_dlst **head_b);

void rra(t_dlst **head_a);
void rrb(t_dlst **head_b);
void rrr(t_dlst **head_a, t_dlst **head_b);

void pa(t_dlst **head_a, t_dlst **head_b);
void pb(t_dlst **head_a, t_dlst **head_b);

void del_lst(t_dlst *lst);
/**************************Все до этого не мое*********************/

typedef struct	s_push_swap_frame
{
    int MIN; //мин. значение
    int LEN_A; //кол-во символов
    int LEN_B;
    int MEDIAN_A; //медианы
	int MEDIAN_B;

    t_dlst *a; //стэк а
    t_dlst *b; //стэк b

    //переменные для сортировок больших порядков
    t_dlst *fst;
    t_dlst *sec;
	int depth1;
    int depth2;
    int com1[3][2];
	int com2[3][2];
	int scroll1;
	int scroll2;

    //переменные для  sort_2-5
	int temp;
	int top;
	int mid;
	int bot;

	//кейсы для sort  5
	int	*stages; //Рубежи
}				t_frame;

void 	sort_2(t_frame *fr);
void	sort_3(t_frame *fr);
void	sort_4(t_frame *fr);
void	sort_5(t_frame *fr);
void	sort_large(t_frame *fr);
void	sort_chunk(t_frame *fr, int st_min, int st_max);

void	search_fs(t_frame *fr, int min, int max);
void	calc_com_table(t_frame *fr);
int		choice_opt(t_frame *fr);
#endif //PUSH_SWAP_PUSH_SWAP_H
