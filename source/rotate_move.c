/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:55:47 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/25 19:38:15 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ra(t_stack **a)
{
	t_stack *last;
	t_stack *swap;

	swap = NULL;
	last = NULL;
	if ((*a) == NULL)
		return ;
	swap = (*a)->next;
	last = (*a)->next;
	(*a)->next = NULL;
	while (last->next != NULL)
		last = last->next;
	last->next = *a;
	*a = swap;
}

void rb(t_stack **b)
{
	t_stack *last;
	t_stack *swap;

	swap = NULL;
	last = NULL;
	if ((*b) == NULL)
		return ;
	swap = (*b)->next;
	last = (*b)->next;
	(*b)->next = NULL;
	while (last->next != NULL)
		last = last->next;
	last->next = *b;
	*b = swap;
}

void	rr(t_stack **a, t_stack **b)
{
	if ((*a) == NULL || (*b) == NULL)
		return ;
	ra(a);
	rb(b);
}
/*
void	rra(t_stack **a)
{
	t_stack *last;
	t_stack *swap;

	last = NULL;
	swap = NULL;
	if ((*a) == NULL)
		return ;
	last = (*a);
	while (last->next != NULL)
		last = last->next;
	swap = (*a)->next;
	(*a) = last;
}
*/
