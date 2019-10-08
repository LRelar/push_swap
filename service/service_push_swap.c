#include "../includes/push_swap.h"
#include "../includes/service.h"

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
	n = (fr->LEN > 100) ? 11 : 5;
	div = fr->LEN / n;
	mod = fr->LEN % n;
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

//TODO 1st, 2d,  и глубины  должны быть обнулены перед передачей и после каждой переброски пересчет LEN MED_A MED_B  и обнуление массива команд
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
		if ((fr->fst == NULL) && (fr->depth[0])++)
			head = head->next;
		if ((fr->sec == NULL) && (fr->depth[1])++)
			tail = tail->prev;
	}
}

void	s_calc_com_table(t_frame *fr)
{
        if (fr->depth[i] <= fr->MEDIAN_A)
            fr->com1[0][0] = 1;
}