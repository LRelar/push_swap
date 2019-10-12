/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:35:16 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/09 18:59:57 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/service.h"

//TODO проверить изменяемость
static void reverse(int com[3][2])
{
	int j;

	j = (com[0][0] > 0) ? 0 : 1;
	if (com[0][j] < com[1][j])
	{
		com[1][j] -= com[0][j];
		com[2][j] = com[0][j];
		com[0][j] = 0;
	}
	else
	{
		com[0][j] += com[1][j];
		com[2][j] = com[1][j];
		com[1][j] = 0;
	}
}

//TODO 1st, 2d,  и глубины  должны быть обнулены перед передачей
// после каждой переброски пересчет LEN_A_B MED_A_B  и обнуление массива команд
// scroll выставляется перед расчетами в 0
void	search_fs(t_frame *fr, int min, int max)
{
	t_dlst *head;
	t_dlst *tail;

	head = fr->a;
	tail = head->prev;
	while (head != tail)
	{
		if ((head->data >= min) && (head->data <= max) && ( fr->fst == NULL))
			fr->fst = head;
		if ((tail->data >= min) && (tail->data <= max) && (fr->sec == NULL))
			fr->sec = tail;
		if ((fr->fst != NULL) && (fr->sec != NULL))
			break;
		if ((fr->fst == NULL) && (fr->depth1)++)
			head = head->next;
		if ((fr->sec == NULL) && (fr->depth2)++)
			tail = tail->prev;
	}
}

void	calc_com_table(t_frame *fr)
{
	(fr->depth1 <= fr->MEDIAN_A) ? (fr->com1[0][0] = fr->depth1) :
	(fr->com1[0][1] = fr->LEN_A - fr->depth1);
	(fr->depth2 < fr->MEDIAN_A) ? (fr->com2[0][1] = fr->depth2 + 1) :
	(fr->com2[0][1] = fr->LEN_A - fr->depth2 - 1);
	fr->depth1 = s_hm_skip_b(fr->b, fr->fst->data);
	fr->depth2 = s_hm_skip_b(fr->b, fr->sec->data);
	if (fr->depth1 <= fr->MEDIAN_B)
		fr->com1[1][0] = fr->depth1;
	else
	{
		fr->com1[1][1] = fr->LEN_B - fr->depth1;
		fr->scroll1 = 1;
	}
	if (fr->depth2 <= fr->MEDIAN_B)
		fr->com2[1][0] = fr->depth2;
	else
	{
		fr->com2[1][1] = fr->LEN_B - fr->depth2;
		fr->scroll2 = 1;
	}
	reverse(fr->com1);
	reverse(fr->com2);
}

int	choice_opt(t_frame *fr)
{
	int i;
	int j;
	int score;

	i = 0;
	j = 0;
	score = 0;
	while (i < 3)
	{
		while (j < 2)
		{
			score += fr->com1[i][j];
			score -= fr->com2[i][j];
			j++;
		}
		i++;
	}
	if (score < 0)
		return (1);
	else
		return (2);
}
