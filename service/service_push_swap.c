/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:42:05 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/10/08 20:51:49 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
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

int		s_hm_skip(t_dlst *head, int val)
{
	int i;
	t_dlst *temp;

	i = 0;
	temp = head;
	if (!temp)
		return (i);
	while ((temp->next != head) && (val < temp->data))
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	s_split_chunks(t_frame *fr)
{
	int n;
	int div;
	int temp;
	int mod;
	int i;

	i = 0;
	n = (fr->LEN_A > 100) ? 11 : 5;
	div = fr->LEN_A / n;
	mod = fr->LEN_A % n;
	temp = fr->MIN;
	while (--n >= 0)
	{
		fr->stages[i++] = temp;
		temp = temp + div;
		if (n == 0)
			fr->stages[i++] = temp + mod;
		else
			fr->stages[i++] = temp;
		temp++;
	}
}

//TODO 1st, 2d,  и глубины  должны быть обнулены перед передачей
// после каждой переброски пересчет LEN_A_B MED_A_B  и обнуление массива команд
// scroll выставляется перед расчетами в 0
void	s_search_fs(t_frame *fr, int min, int max)
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

void	s_calc_com_table(t_frame *fr)
{
	(fr->depth1 <= fr->MEDIAN_A) ? (fr->com1[0][0] = fr->depth1) :
		(fr->com1[0][1] = fr->LEN_A - fr->depth1);
	(fr->depth2 < fr->MEDIAN_A) ? (fr->com2[0][1] = fr->depth2 + 1) :
		(fr->com2[0][1] = fr->LEN_A - fr->depth2 - 1);
	fr->depth1 = s_hm_skip(fr->b, fr->fst->data);
	fr->depth2 = s_hm_skip(fr->b, fr->sec->data);
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
/*
 * if (fr->depth1 <= fr->MEDIAN_A)
		fr->com1[0][0] = fr->depth1;
	else
		fr->com1[0][1] = fr->LEN_A - fr->depth1;
	if (fr->depth2 < fr->MEDIAN_A)
		fr->com2[0][1] = fr->depth2 + 1;
	else
		fr->com2[0][1] = fr->LEN_A - fr->depth2 - 1;
	fr->depth1 = s_hm_skip(fr->b, fr->fst->data);
	fr->depth2 = s_hm_skip(fr->b, fr->sec->data);
	if (fr->depth1 <= fr->MEDIAN_B)
		fr->com1[1][0] = fr->depth1;
	else
	{
		fr->com1[1][1] = fr->LEN_B - fr->depth1;
		fr->scroll = 1;
	}
	if (fr->depth2 <= fr->MEDIAN_B)
		fr->com2[1][0] = fr->depth2;
	else
	{
		fr->com2[1][1] = fr->LEN_B - fr->depth2;
		fr->scroll = 1;
	}
 * */