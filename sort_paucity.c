#include "./includes/push_swap.h"

void	sort_2(t_dlst **head_a)
{
	if ((*head_a)->data > (*head_a)->next->data)
		sa(head_a);
}

/*TODO
 * подстроить под фрэйм
*/
void	sort_3(t_frame *frame)
{
	frame->top = frame->a->data;
	frame->mid = frame->a->next->data;
	frame->bot = frame->a->prev->data;
	if ((frame->top < frame->mid) && (frame->mid > frame->bot) && (frame->bot < frame->top))
		rra(&(frame->a));
	if ((frame->top < frame->mid) && (frame->mid > frame->bot) && (frame->bot > frame->top))
	{
		sa(&(frame->a));
		ra(&(frame->a));
	}
	if ((frame->top > frame->mid) && (frame->mid < frame->bot) && (frame->bot < frame->top))
		ra(&(frame->a));
	if ((frame->top > frame->mid) && (frame->mid < frame->bot) && (frame->bot > frame->top))
		sa(&(frame->a));
	if ((frame->top > frame->mid) && (frame->mid > frame->bot) && (frame->bot < frame->top))
	{
		sa(&(frame->a));
		rra(&(frame->a));
	}
}

void	sort_4(t_frame *frame)
{
	pb(&(frame->a), &(frame->b));
	sort_3(&(frame->a));
	temp = (*head_b)->data;
	frame->top = frame->a->data;
	frame->mid = frame->a->next->data;
	frame->bot = frame->a->prev->data;
	if ((temp < frame->top) && (temp < frame->mid) && (temp < frame->bot))
		pa(&(frame->a), head_b);
	if ((temp > frame->top) && (temp < frame->mid) && (temp < frame->bot))
	{
		ra(&(frame->a));
		pa(&(frame->a), head_b);
		rra(&(frame->a));
	}
	if ((temp > frame->top) && (temp > frame->mid) && (temp < frame->bot))
	{
		ra(&(frame->a));
		ra(&(frame->a));
		pa(&(frame->a), head_b);
		ra(&(frame->a));
		ra(&(frame->a));
	}
}
