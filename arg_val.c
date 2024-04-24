/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:29 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/24 02:37:47 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_signal (char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	check_chars(char **arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] != NULL)
	{
		while (*arg[j] != '\0')
		{
			if (check_spaces(*arg[j]) != 1 || ft_isdigit(*arg[j]) != 1 || check_signal(*arg[j]) != 1)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	check_dup_num(int *arr)
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
			i = bubble;
			bubble++;
		}
	}
	return (1);
}

int	check_overflow(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int arg_val(char **argv)
{
	if (!argv[1])
	{
		ft_puterror();
		return (1);
	}
	if (check_chars(argv) == 1)
		return (1);

}
