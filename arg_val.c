/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:29 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/21 16:40:24 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_chars(char c)
{
	if (check_spaces(c) != 1 || ft_isdigit(c) != 1 || check_signal(c) != 1)
		return (0);
	return (1);
}

static int	check_args(char **argv)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	while (argv[cmp] != '\0')
	{
		if (check_chars(argv[cmp][i]) == 0)
		{
			ft_puterror();
			return (1);
		}
		if (argv[cmp][i] == '\0')
		{
			cmp++;
			i = 0;
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
