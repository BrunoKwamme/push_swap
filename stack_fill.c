/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:23 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/24 03:08:00 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_fill (t_list *a, int *arg_arr)
{
	int	i;

	i = 0;
	while(i < arr_len(arg_arr))
	{
		a = ft_lstnew(&arg_arr[i]);
		i++;
	}
}
