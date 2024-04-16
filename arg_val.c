/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:29 by bkwamme           #+#    #+#             */
/*   Updated: 2024/03/26 17:51:55 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(char **argv)
{
	int	i;
	int	cmp;

	i = 1;
	cmp = 0;
	while (argv[1][i] != '\0' || argv[1][cmp] != '\0')
	{
		if (argv[1][i] == argv[1][cmp] && check_spaces(argv[1][i]) != 0)
		{
			ft_puterror();
			return (1);
		}
		if (argv[1][i] == '\0')
		{
			cmp++;
			i = cmp + 1;
		}
		i++;
	}
	return (0);
}

static int	check_chars(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_isalnum(argv[1][i]) ==  1 && check_spaces(argv[1][i]) == 1)
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
		ft_puterror();
		return (1);
	}
	if (check_chars(argv) == 1 || check_duplicates(argv) == 1)
		return (0);
}
