/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:23 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/25 10:31:29 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_fill (t_stack *a, int *arg_arr)
{
	int	i;
	int	arg_len;

	arg_len = arr_len(arg_arr);
	i = 0;
	while(i < arr_len(arg_arr))
	{
		a = ft_calloc(sizeof(t_stack), 1);
		a = ft_lstnew(&arg_arr[i]);
		a->data = arg_arr[arg_len];
		a->i = raddix_i(arg_arr);
		i++;
	}
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
}

int main()

{
	int vec = {2, 1, 9, 10};

	return 0;
}
