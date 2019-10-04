#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

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

/**************************Все до этого не мое*********************/
#include "service.h"
#include <stdlib.h>

typedef struct	s_push_swap_frame
{
    int MIN; //мин. значение
    int MAX; //макс. значение
    int LEN; //кол-во символов
    int MEDIAN; //медиана

    t_dlst *a; //стэк а
    t_dlst *b; //стэк b

    //переменные для  sort_2-5
	int temp;
	int top;
	int mid;
	int bot;

	int	*stages //Рубежи
}				t_frame;
/*********************Сервисные функции push_swap*********************/

void	s_init_tmb(t_frame *fr);
t_frame	s_create_frame(t_dlst *a, t_dlst *b, int len, int min, int max);
int		s_hm_skip(t_dlst *head, int val);

/*********************************************************************/

void 	sort_2(t_frame *fr);
void	sort_3(t_frame *fr);
void	sort_4(t_frame *fr);
void	sort_5(t_frame *fr);

#endif //PUSH_SWAP_PUSH_SWAP_H
