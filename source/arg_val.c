/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:29 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/26 16:49:25 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_chars(char **arg)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 1;
	j = 0;
	while (arg[i] != NULL)
	{
		while (arg[i][j] != '\0')
		{
			if (ft_isdigit(arg[i][j]) == 1 && (arg[i][j + 1] == ' '
						|| arg[i][j + 1] == '\0'))
				flag++;
			if (arg[i][j] != ' ' && ft_isdigit(arg[i][j]) != 1
					&& (arg[i][j] != '+' && arg[i][j] != '-'))
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (flag);
}

static int	check_dup_num(long *arr, int arr_len)
{
	int	i;
	int	bubble;

	bubble = 0;
	i = 1;
	while (i < arr_len && bubble < arr_len)
	{
		if (arr[bubble] == arr[i])
			return (0);
		if (i + 1 == arr_len)
		{
			bubble++;
			i = bubble;
		}
		i++;
	}
	return (1);
}

static int	check_overflow(long *arr, int arr_len)
{
	int	i;

	i = 0;
	while (i < arr_len)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	arg_val(char **argv)
{
	int	arr_len;

	arr_len = check_chars(argv);
	if (arr_len < 0)
		return (-1);
	return (arr_len);
}

int	array_val(long *arr, int arr_len)
{
	if (!arr)
		return (1);
	if (check_overflow(arr, arr_len) == 0 || check_dup_num(arr, arr_len) == 0)
		return (1);
	return (0);
}
