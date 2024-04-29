/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:08 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/29 13:22:52 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	operations_management(t_stack **a, t_stack **b)
{
	int	a_size;

	if ((*a) == NULL)
		return ;
	a_size = stack_size((*a));
	if (is_stack_ordered(a))
		return ;
	else if (a_size == 2)
		sa(a);
	else if (a_size == 3)
		three_nodes(a);
	else if (a_size == 4 || a_size == 5)
		five_nodes(a, b);
	else if (a_size > 5)
		more_than_five(a, b);
}

void	free_all(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	while ((*a))
	{
		temp = (*a);
		(*a) = (*a)->next;
		free(temp);
	}
	if ((*b))
		free((*b));
}

int	main(int argc, char **argv)
{
	long	*arr;
	int		arr_len;
	t_stack	*a;
	t_stack	*b;

	arr_len = arg_val(argv);
	arr = NULL;
	a = NULL;
	b = NULL;
	if (argc <= 2 && (*argv[1] == '\0' || (argv[1][0] == ' ' && arr_len == 0)))
		return (1);
	if (arr_len < 0)
		return (ft_puterror(), 1);
	if (argc == 2)
		arr = arg_into_array(argv, argc);
	else
		arr = mult_arg_array(argv, argc);
	if (array_val(arr, arr_len) == 1)
		return (ft_puterror(), free(arr), 1);
	create_stack(&a, arr, arr_len);
	create_stack_b(&b);
	operations_management(&a, &b);
	return (free(arr), free_all(&a, &b), 0);
}
