/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:29 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/25 19:33:51 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_chars(char **arg)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arg[i] != NULL)
	{
		while (arg[i][j] != '\0')
		{
			if (check_spaces(arg[i][j]) != 1 || ft_isdigit(arg[i][j]) != 1 || check_signal(arg[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

static int	check_dup_num(long *arr)
{
	int	i;
	int bubble;

	bubble = 0;
	i = 1;

	while (arr[i] != '\0' && arr[bubble] != '\0')
	{
		if (arr[bubble] == arr[i])
			return (0);
		i++;
		if (arr[i] == '\0')
		{
			bubble++;
			i = bubble + 1;
		}
	}
	return (1);
}

static int	check_overflow(long *arr)
{
	int	i;
	int x;

	x = 0;
	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int arg_val(char **argv)
{
	if (check_chars(argv) == 1)
		return (1);
	return (0);
}

int	array_val(long *arr)
{
	if (!arr)
		return (1);
	if (check_overflow(arr) == 0 || check_dup_num(arr) == 0)
		return (1);
	return (0);
}
