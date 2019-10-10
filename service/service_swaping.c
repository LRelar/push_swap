/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:47:30 by sstark            #+#    #+#             */
/*   Updated: 2019/10/10 17:59:06 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/* swap first and second elements */

void	sa(t_dlst **first)
{
	t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*first)->prev;
	second = (*first)->next;
	third = (*first)->next->next;
	if (tail == second || tail == *first)
		return ;
	else
	{
		(*first)->next = third;
		(*first)->prev = second;
		second->prev = tail;
		second->next = (*first);
		if (tail == third)
			tail->prev = (*first);
		tail->next = second;
		*first = second;
	}
	write(1, "sa\n", 4);
}

void	sb(t_dlst **first)
{
	t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*first)->prev;
	second = (*first)->next;
	third = (*first)->next->next;
	if (tail == second || tail == *first)
		return ;
	else
	{
		(*first)->next = third;
		(*first)->prev = second;
		second->prev = tail;
		second->next = (*first);
		if (tail == third)
			tail->prev = (*first);
		tail->next = second;
		*first = second;
	}
	write(1, "sb\n", 4);
}

void	ss(t_dlst **a, t_dlst **b)
{
	sa_b(a);
	sa_b(b);
	write(1, "ss\n", 4);
}

/* first element moving to the third place */

void	ra(t_dlst **first)
{
    t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*first)->prev;
	second = (*first)->next;
	third = (*first)->next->next;
	(*first)->next = third->next;
	(*first)->prev = third;
	third->next = *first;
	if (tail == third)
		second->prev = *first;
	if (tail != third)
	{
		second->prev = tail;
		tail->next = second;
	}
	*first = second;
	write(1, "ra\n", 4);
}

void	rb(t_dlst **first)
{
    t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*first)->prev;
	second = (*first)->next;
	third = (*first)->next->next;
	(*first)->next = third->next;
	(*first)->prev = third;
	third->next = *first;
	if (tail == third)
		second->prev = *first;
	if (tail != third)
	{
		second->prev = tail;
		tail->next = second;
	}
	*first = second;
	write(1, "rb\n", 4);
}

void	rr(t_dlst **a, t_dlst **b)
{
	ra_b(a);
	ra_b(b);
	write(1, "rr\n", 4);
}

/* third element moving to the first place */

void	rra(t_dlst **first)
{
	t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*first)->prev;
	second = (*first)->next;
	third = (*first)->next->next;
	if (tail != third)
	{
		(*first)->prev = third;
		second->next = third->next;
		third->next->prev = second;
		third->next = *first;
		third->prev = tail;
		tail->next = third;
	}
	*first = third;
	write(1, "rra\n", 4);
}

void	rrb(t_dlst **first)
{
	t_dlst *tail;
	t_dlst *second;
    t_dlst *third;

	tail = (*first)->prev;
	second = (*first)->next;
	third = (*first)->next->next;
	if (tail != third)
	{
		(*first)->prev = third;
		second->next = third->next;
		third->next->prev = second;
		third->next = *first;
		third->prev = tail;
		tail->next = third;
	}
	*first = third;
	write(1, "rrb\n", 4);
}

void	rrr(t_dlst **a, t_dlst **b)
{
	rra_b(a);
	rra_b(b);
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
