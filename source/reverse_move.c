/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:21:54 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/26 15:01:57 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*penultimate;

	last = NULL;
	penultimate = NULL;
	if ((*a) == NULL)
		return ;
	penultimate = (*a);
	last = (*a);
	while (last->next != NULL)
		last = last->next;
	while (penultimate->next != last)
		penultimate = penultimate->next;
	penultimate->next = NULL;
	last->next = (*a);
	*a = last;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*penultimate;

	last = NULL;
	penultimate = NULL;
	if ((*b) == NULL)
		return ;
	penultimate = (*b);
	last = (*b);
	while (last->next != NULL)
		last = last->next;
	while (penultimate->next != last)
		penultimate = penultimate->next;
	penultimate->next = NULL;
	last->next = (*b);
	*b = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((*a) == NULL || (*b) == NULL)
		return ;
	rra(a);
	rrb(b);
}
