/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:23 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/25 14:24:47 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack **stack, long *arr)
{
	int array_len;
	int	i;
	t_stack	*a;
	t_stack *swap;


	swap = NULL;
	array_len = arr_len(arr);
	i = 0;
	while (i < array_len)
	{
		a = ft_calloc(sizeof(t_stack), 1);
		a->data = arr[i];
		a->next = swap;
		swap = a;
		i++;
	}
	*stack = a;
}
/*
t_stack	stack_fill (int *arg_arr)
{
	int	i;
	int	arg_len;
	t_stack	*a;

	a = NULL;
	arg_len = arr_len(arg_arr);
	i = 0;
	while(i < arr_len(arg_arr))
	{
		a = ft_calloc(sizeof(t_stack), 1);
		a = ft_lstnew(&arg_arr[i]);
		a->data = arg_arr[arg_len];
		a->i = 3;//raddix_i(arg_arr);
		a->next = NULL;
		i++;
	}
	return (a);
}

int	raddix_i(int *array)
{
	int	i;
	int bubble;
	int	swap;

	swap = 0;
	i = 1;
	bubble = 0;
	while (array[i] != '\0')
	{
		if (array[i] < array[bubble])
		{
			swap = array[bubble];
			array[bubble] = array[i];
			array[i] = swap;
			i = bubble;
		}
		if (array[i + 1] == "\0")
		{
			bubble++;
			i = bubble;
		}
		i++;
	}
}*/
