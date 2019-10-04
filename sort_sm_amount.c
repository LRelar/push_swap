#include "./includes/push_swap.h"

void	sort_2(t_frame *fr)
{
	if (fr->a->data > fr->a->next->data)
		sa(&(fr->a));
}

void	sort_3(t_frame *fr)
{
	s_init_tmb(fr);
	if ((fr->top < fr->mid) && (fr->mid > fr->bot) && (fr->bot < fr->top))
		rra(&(fr->a));
	if ((fr->top < fr->mid) && (fr->mid > fr->bot) && (fr->bot > fr->top))
	{
		sa(&(fr->a));
		ra(&(fr->a));
	}
	if ((fr->top > fr->mid) && (fr->mid < fr->bot) && (fr->bot < fr->top))
		ra(&(fr->a));
	if ((fr->top > fr->mid) && (fr->mid < fr->bot) && (fr->bot > fr->top))
		sa(&(fr->a));
	if ((fr->top > fr->mid) && (fr->mid > fr->bot) && (fr->bot < fr->top))
	{
		sa(&(fr->a));
		rra(&(fr->a));
	}
}

void	sort_4(t_frame *fr)
{
	pb(&(fr->a), &(fr->b));
	sort_3(fr);
	fr->temp = (fr->b)->data;
	s_init_tmb(fr);
	if ((fr->temp < fr->top) && (fr->temp < fr->mid) && (fr->temp < fr->bot))
		pa(&(fr->a), &(fr->b));
	if ((fr->temp > fr->top) && (fr->temp < fr->mid) && (fr->temp < fr->bot))
	{
		ra(&(fr->a));
		pa(&(fr->a), &(fr->b));
		rra(&(fr->a));
	}
	if ((fr->temp > fr->top) && (fr->temp > fr->mid) && (fr->temp < fr->bot))
	{
		s_rep_ra(&(fr->a), 2);
		pa(&(fr->a), &(fr->b));
		s_rep_ra(&(fr->a), 2);
	}
}

void	sort_5(t_frame *fr)
{
	s_rep_pb(&(fr->a), &(fr->b), 2);
	sort_3(fr);
	if (fr->b->data < fr->b->next->data)
		rb(&(fr->b));

}

