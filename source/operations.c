/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:38:49 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/29 12:50:01 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_nodes(t_stack **a)
{
	if (stack_size(*a) == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
		return ;
	}
	if ((*a)->data > (*a)->next->data)
		sa(a);
	if ((*a)->data > (*a)->next->next->data)
		rra(a);
	if ((*a)->next->data > (*a)->next->next->data)
	{
		rra(a);
		sa(a);
	}
}

void	five_nodes(t_stack **a, t_stack **b)
{
	while (stack_size((*a)) > 3 && (*a)->next != NULL)
	{
		while ((*a)->i == 0 || (*a)->i == 1)
			pb(a, b);
		if (stack_size((*a)) > 3)
			ra(a);
	}
	three_nodes(a);
	while (stack_size((*b)) != 0)
		pa(a, b);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	more_than_five(t_stack **stack_a, t_stack **stack_b)
{
	int	iter;
	int	begin;

	if (is_stack_ordered(stack_a) == 1)
		return ;
	begin = 0;
	iter = binary_limit(stack_size((*stack_a)));
	while (iter > 0)
	{
		order_by_radix(stack_a, stack_b, begin);
		iter--;
		begin++;
	}
	while (stack_size((*stack_b)) > 0)
	{
		pa(stack_a, stack_b);
	}
}

void	order_by_radix(t_stack **stack_a, t_stack **stack_b, int ind)
{
	int	count_b;
	int	count_a;

	count_b = stack_size((*stack_b));
	while (count_b > 0 && (*stack_b)->next != NULL)
	{
		if (((*stack_b)->i >> ind & 1) == 1)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		count_b--;
	}
	count_a = stack_size((*stack_a));
	while (count_a > 0 && (*stack_a)->next != NULL)
	{
		if (((*stack_a)->i >> ind & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		count_a--;
	}
}
