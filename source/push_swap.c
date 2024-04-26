/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:08 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/26 06:37:09 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *a)
{
	t_stack *sup;
	sup = a;
	while (sup != NULL)
	{
		ft_printf("%d\n", sup->data);
		sup = sup->next;
	}
}

void operations_management(t_stack **a, t_stack **b)
{
	int	a_size;

	a_size = stack_size((*a));
	if (is_stack_ordered(a))
		return ;
	if (a_size <= 3)
		three_nodes(a);
	if (a_size > 3 && a_size <= 5)
	{
		ft_printf("aaaaaa\n");
		five_nodes(a, b);
	}
	if (a_size > 5)
		more_than_five(a, b);
}

int main(int argc, char **argv)
{
	long	*arr;
	long	*stack_i;
	int		arr_len;
	t_stack *a;
	t_stack *b;

	arr_len = arg_val(argv);
	arr = NULL;
	stack_i = NULL;
	b = NULL;
	a = NULL;
	if (argc < 2 || *argv[1] == '\0' || *argv[1] == ' ')
		return (1);
	if (arr_len < 0)
	{
		ft_puterror();
		return (1);
	}
	arr = arg_into_array(argv, argc);
	stack_i = stack_index(arr, arr_len);
	if (array_val(arr) == 1)
	{
		ft_puterror();
		free(arr);
		return (1);
	}
	create_stack(&a, arr, stack_i, arr_len);
	create_stack_b(&b);
	operations_management(&a, &b);
	free(arr);
	return 0;
}
