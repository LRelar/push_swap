/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:47:30 by sstark            #+#    #+#             */
/*   Updated: 2019/10/10 20:50:23 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* swap first and second elements */

void sa(t_dlst **head_a)
{
	t_dlst *temp;

	if (((*head_a) != NULL) && (*head_a)->next != (*head_a))
	{
		temp = *head_a;
		(*head_a)->next->prev = (*head_a)->prev;
		(*head_a)->prev->next = (*head_a)->next;
		(*head_a) = (*head_a)->next;
		temp->next = (*head_a)->next;
		temp->prev = *head_a;
		(*head_a)->next->prev = temp;
		(*head_a)->next = temp;
	}
	write(1, "sa\n", 3);
}

void sb(t_dlst **head_b)
{
	t_dlst *temp;

	if (((*head_b) != NULL) && (*head_b)->next != (*head_b))
	{
		temp = *head_b;
		(*head_b)->next->prev = (*head_b)->prev->next;
		(*head_b)->prev->next = (*head_b)->next;
		(*head_b) = (*head_b)->next;
		temp->next = (*head_b)->next;
		temp->prev = *head_b;
		(*head_b)->next->prev = temp;
		(*head_b)->next = temp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_dlst **head_a, t_dlst **head_b)
{
	t_dlst *temp;

	if (((*head_a) != NULL) && (*head_a)->next != (*head_a))
	{
		temp = *head_a;
		(*head_a)->next->prev = (*head_a)->prev->next;
		(*head_a)->prev->next = (*head_a)->next;
		(*head_a) = (*head_a)->next;
		temp->next = (*head_a)->next;
		temp->prev = *head_a;
		(*head_a)->next->prev = temp;
		(*head_a)->next = temp;
	}
	if (((*head_b) != NULL) && (*head_b)->next != (*head_b))
	{
		temp = *head_b;
		(*head_b)->next->prev = (*head_b)->prev->next;
		(*head_b)->prev->next = (*head_b)->next;
		(*head_b) = (*head_b)->next;
		temp->next = (*head_b)->next;
		temp->prev = *head_b;
		(*head_b)->next->prev = temp;
		(*head_b)->next = temp;
	}
	write(1, "ss\n", 3);
}

/* first element moving to the third place */

void ra(t_dlst **head_a)
{
   *head_a = (*head_a)->next;
   write(1, "ra\n", 3);
}

void rb(t_dlst **head_b)
{
	*head_b = (*head_b)->next;
	write(1, "rb\n", 3);
}

void	rr(t_dlst **a, t_dlst **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	write(1, "rr\n", 3);
}

/* third element moving to the first place */

void rra(t_dlst **head_a)
{
	*head_a = (*head_a)->prev;
	write(1, "rra\n", 4);
}

void rrb(t_dlst **head_b)
{
	*head_b = (*head_b)->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_dlst **a, t_dlst **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	write(1, "rrr\n", 4);
}

/* first element from stack b move to stack a */

void	pa(t_dlst **a, t_dlst **b)
{
	t_dlst	*temp;

	if ((b != NULL) && (*b != NULL))
    {
	    temp = *b;
        (*b)->next->prev = (*b)->prev;
        (*b)->prev->next = (*b)->next;
        (*b) = (*b)->next;
        temp->next = (*a);
        temp->prev = (*a)->prev;
        (*a)->prev->next = temp;
        (*a)->prev = temp;
        *a = temp;
    }
	write(1, "pa\n", 3);
}

/* first element from stack a move to stack b */

void	pb(t_dlst **a, t_dlst **b)
{
    t_dlst	*temp;

    if ((a != NULL) && (*a != NULL))
    {
        temp = *a;
        (*a)->next->prev = (*a)->prev;
        (*a)->prev->next = (*a)->next;
        (*a) = (*a)->next;
        temp->next = (*b);
        temp->prev = (*b)->prev;
        (*b)->prev->next = temp;
        (*b)->prev = temp;
        *b = temp;
    }
	write(1, "pb\n", 3);
} 
