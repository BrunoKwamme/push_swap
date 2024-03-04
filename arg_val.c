/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:29 by bkwamme           #+#    #+#             */
/*   Updated: 2024/03/04 17:44:09 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_spaces(char c)
{
	if (c == 32 || (c >= 7 && c <= 13))
		return (0);
	return (1);
}

static int	check_duplicates(char **argv)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 1;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == argv[1][cmp])
		{
			ft_puterror();
			return (1);
		}
		if (argv[1][cmp] == '\0')
		{
			i++;
			cmp = i+1;
		}
		cmp++;
	}
	return (0);
}

static int	check_chars(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if ((argv[1][i] < 48 || argv[1][i] > 58) && check_spaces(argv[1][i]) == 1)
		{
			ft_puterror();
			return (1);
		}
		i++;
	}
	return (0);
}

int arg_val(char **argv)
{
	if (!argv[1])
	{
		ft_error();
		return (1);
	}
	if (check_chars(argv) == 1 || check_duplicates(argv) == 1)
		return (1);
}
