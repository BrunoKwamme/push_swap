/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:01:57 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/25 23:42:42 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		ft_printf("sa\n");
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
		ft_printf("pb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if (stack_size(*a) < 2 || stack_size(*b) < 2)
		return ;
	sa(a);
	sb(b);
}
