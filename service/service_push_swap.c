#include "../includes/push_swap.h"

void	s_init_tmb(t_frame *fr)
{
	fr->top = fr->a->data;
	fr->mid = fr->a->next->data;
	fr->bot = fr->a->prev->data;
}

t_frame	s_create_frame(t_dlst *a, t_dlst *b, int len, int min, int max)
{
	t_frame *fr;

	fr = (t_frame *)malloc(sizeof(t_frame));
	if (len > 5)
		fr->stages = (int *)malloc(sizeof(int) * ((len <= 100) ? 10 : 22));
	else
		fr->stages = NULL;
	fr->MIN = min;
	fr->MAX = max;
	fr->LEN = len;
	fr->MEDIAN = len / 2;
	fr->a = a;
	fr->b = b;
	fr->temp = 0;
	fr->top = 0;
	fr->mid = 0;
	fr->bot = 0;
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
//TODO забиение массива на отрезки

