/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_in_cr_frame.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:43:01 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/08 18:44:25 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include "../includes/service.h"

//TODO проверить инит + сделать пересчёт
void	s_init_tmb(t_frame *fr)
{
    fr->top = fr->a->data;
    fr->mid = fr->a->next->data;
    fr->bot = fr->a->prev->data;
}

t_frame	*s_create_frame(t_dlst *a, t_dlst *b, int len, int min, int max)
{
    t_frame *fr;

    fr = (t_frame *)malloc(sizeof(t_frame));
    if (len > 5)
    {
        fr->stages = (int *) malloc(sizeof(int) * ((len <= 100) ? 10 : 22));
        if (fr->stages == NULL)
            return (s_delete_frame(fr));
    }
    else
        fr->stages = NULL;
    fr->MIN = min;
    fr->MAX = max;
    fr->LEN_A = len;
    fr->MEDIAN_A = len / 2;
    fr->MEDIAN_B = 0;
    fr->a = a;
    fr->b = b;
    fr->temp = 0;
    fr->top = 0;
    fr->mid = 0;
    fr->bot = 0;
    return (fr);
}

t_frame	*s_delete_frame(t_frame *frame)
{
    if (frame != NULL)
    {
        del_lst(frame->a);
        del_lst(frame->a);
        free(frame->stages);
    }
    return  (NULL);
}
