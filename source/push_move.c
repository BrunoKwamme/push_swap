/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:56:23 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/29 13:16:07 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*swap;

	swap = NULL;
	if ((*b) == NULL || (*b)->i == -1)
		return ;
	swap = (*a);
	*a = *b;
	*b = (*b)->next;
	(*a)->next = swap;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*swap;

	swap = NULL;
	if ((*a) == NULL)
		return ;
	if ((*b)->i == -1)
		free((*b));
	else
		swap = (*b);
	*b = *a;
	*a = (*a)->next;
	(*b)->next = swap;
	ft_printf("pb\n");
}
