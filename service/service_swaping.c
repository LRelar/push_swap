/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:47:30 by sstark            #+#    #+#             */
/*   Updated: 2019/10/10 19:00:12 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* swap first and second elements */

void sa(t_dlst **head_a, int flag)
{
	t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*head_a)->prev;
	second = (*head_a)->next;
	third = (*head_a)->next->next;
	if (tail == second || tail == *head_a)
		return ;
	else
	{
		(*head_a)->next = third;
		(*head_a)->prev = second;
		second->prev = tail;
		second->next = (*head_a);
		if (tail == third)
			tail->prev = (*head_a);
		tail->next = second;
		*head_a = second;
	}
	if (flag)
		write(1, "sa\n", 4);
}

void sb(t_dlst **head_b, int flag)
{
	t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*head_b)->prev;
	second = (*head_b)->next;
	third = (*head_b)->next->next;
	if (tail == second || tail == *head_b)
		return ;
	else
	{
		(*head_b)->next = third;
		(*head_b)->prev = second;
		second->prev = tail;
		second->next = (*head_b);
		if (tail == third)
			tail->prev = (*head_b);
		tail->next = second;
		*head_b = second;
	}
	if (flag)
		write(1, "sb\n", 4);
}

void	ss(t_dlst **head_a, t_dlst **head_b)
{
	sa(head_a, 0);
	sb(head_b, 0);
	write(1, "ss\n", 4);
}

/* first element moving to the third place */

void ra(t_dlst **head_a, int flag)
{
    t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*head_a)->prev;
	second = (*head_a)->next;
	third = (*head_a)->next->next;
	(*head_a)->next = third->next;
	(*head_a)->prev = third;
	third->next = *head_a;
	if (tail == third)
		second->prev = *head_a;
	if (tail != third)
	{
		second->prev = tail;
		tail->next = second;
	}
	*head_a = second;
	if (flag)
		write(1, "ra\n", 4);
}

void rb(t_dlst **head_b, int flag)
{
    t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*head_b)->prev;
	second = (*head_b)->next;
	third = (*head_b)->next->next;
	(*head_b)->next = third->next;
	(*head_b)->prev = third;
	third->next = *head_b;
	if (tail == third)
		second->prev = *head_b;
	if (tail != third)
	{
		second->prev = tail;
		tail->next = second;
	}
	*head_b = second;
	if (flag)
		write(1, "rb\n", 4);
}

void	rr(t_dlst **a, t_dlst **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 4);
}

/* third element moving to the first place */

void rra(t_dlst **head_a, int flag)
{
	t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*head_a)->prev;
	second = (*head_a)->next;
	third = (*head_a)->next->next;
	if (tail != third)
	{
		(*head_a)->prev = third;
		second->next = third->next;
		third->next->prev = second;
		third->next = *head_a;
		third->prev = tail;
		tail->next = third;
	}
	*head_a = third;
	if (flag)
		write(1, "rra\n", 4);
}

void rrb(t_dlst **head_b, int flag)
{
	t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*head_b)->prev;
	second = (*head_b)->next;
	third = (*head_b)->next->next;
	if (tail != third)
	{
		(*head_b)->prev = third;
		second->next = third->next;
		third->next->prev = second;
		third->next = *head_b;
		third->prev = tail;
		tail->next = third;
	}
	*head_b = third;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_dlst **a, t_dlst **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}

/* first element from stack b move to stack a */

void	pa(t_dlst **a, t_dlst **b)
{
	t_dlst	*cp_b;
	
	cp_b = (*b)->next;
	(*b)->prev->next = (*b)->next;
	(*b)->next->prev = (*b)->prev;
	(*a)->prev->next = *b;
	(*b)->prev = (*a)->prev;
	(*a)->prev = (*b);
	(*b)->next = (*a);
	*b = cp_b;
	*a = (*a)->prev;
}

/* first element from stack a move to stack b */

void	pb(t_dlst **a, t_dlst **b)
{
	t_dlst	*cp_a;
	
	cp_a = (*a)->next;
	(*a)->prev->next = (*a)->next;
	(*a)->next->prev = (*a)->prev;
	(*b)->prev->next = *a;
	(*a)->prev = (*b)->prev;
	(*b)->prev = (*a);
	(*a)->next = (*b);
	*a = cp_a;
	*b = (*b)->prev;
} 
