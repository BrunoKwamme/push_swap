/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:23 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/26 16:36:11 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	*stack_index(long *array, int arr_len)
{
	long	*stack_i;
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = 0;
	stack_i = ft_calloc(sizeof(long), arr_len);
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{
			if (array[i] > array[j])
				flag++;
			j++;
		}
		stack_i[i] = flag;
		flag = 0;
		i++;
	}
	return (stack_i);
}

void	create_stack(t_stack **stack, long *arr, int arr_len)
{
	long	*stack_i;
	t_stack	*a;
	t_stack	*swap;

	stack_i = stack_index(arr, arr_len);
	swap = NULL;
	while (0 < arr_len)
	{
		a = ft_calloc(sizeof(t_stack), arr_len);
		a->data = arr[--arr_len];
		a->i = stack_i[arr_len];
		a->next = swap;
		swap = a;
	}
	*stack = a;
	free(stack_i);
}

int	is_stack_ordered(t_stack **stack_a)
{
	t_stack	*stack_temp;

	stack_temp = (*stack_a);
	while (stack_temp->next != NULL)
	{
		if (stack_temp->next->i != -1)
		{
			if (stack_temp->data < stack_temp->next->data)
				stack_temp = stack_temp->next;
			else
				return (0);
		}
		else
			stack_temp = stack_temp->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	create_stack_b(t_stack **b)
{
	t_stack	*temp;

	temp = ft_calloc(sizeof(t_stack), 1);
	(*b) = temp;
}
