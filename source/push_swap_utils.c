/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:36:03 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/25 19:15:41 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	check_spaces(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int check_signal (char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

void ft_puterror(void)
{
	write(0, "Error\n", 6);
}

long	ft_atol(const char *nptr)
{
	long	atol;
	int		i;
	int		m;

	i = 0;
	m = 0;
	atol = 0;
	while (nptr[i] == 32 || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		atol = atol * 10 + nptr[i] - 48;
		i++;
	}
	if (nptr[i] != '\0')
		return (-2147483649);
	if (m == 1)
		return (-atol);
	return (atol);
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
