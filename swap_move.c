/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:01:57 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/25 18:20:17 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*swap;
	int	lst_size;

	lst_size = stack_size(*a);
	if (lst_size < 2)
		return ;
	else
	{
		swap = (*a);
		*a = (*a)->next;
		swap->next = (*a)->next;
		(*a)->next = swap;
	}
}

void	sb(t_stack **b)
{
	t_stack	*swap;
	int	lst_size;

	lst_size = stack_size(*b);
	if (lst_size < 2)
		return ;
	else
	{
		swap = (*b);
		*b = (*b)->next;
		swap->next = (*b)->next;
		(*b)->next = swap;
	}
}

void	ss(t_stack **a, t_stack **b)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(*a);
	b_size = stack_size(*b);
	if (a_size < 2 || b_size < 2)
		return ;
	sa(a);
	sb(b);
}
