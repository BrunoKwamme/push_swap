/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:08 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/25 19:34:20 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *a)
{
	t_stack *sup;
	sup = a;
	for (int x = 0; sup != NULL; x++)
	{
		ft_printf("%d\n", sup->data);
		sup = sup->next;
	}
}

int main(int argc, char **argv)
{
	long	*arr;
	t_stack *a;
	t_stack *b;

	b = NULL;
	a = NULL;
	arr = NULL;
	if (argc < 2)
		return (1);
	if (arg_val(argv) == 1)
	{
		ft_puterror();
		return (1);
	}
	arr = arg_into_array(argv, argc);
	if (array_val(arr) == 1)
	{
		ft_puterror();
		free(arr);
		return (1);
	}
	create_stack(&a, arr);
	create_stack(&b, arr);
	ss(&a, &b);
	print_stack(a);
	print_stack(b);
	free(arr);
	//stack_fill(**argv, argc, a);
	return 0;
}
