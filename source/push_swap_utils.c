/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:36:03 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/26 16:20:04 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_splitted_args(char **splitted_args)
{
	int	i;

	i = 0;
	while (splitted_args[i] != NULL)
	{
		free(splitted_args[i]);
		i++;
	}
	free(splitted_args);
}

void	ft_puterror(void)
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

long	ft_atol_mult_arg(const char *nptr)
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
	if (m == 1)
		return (-atol);
	return (atol);
}

int	binary_limit(int r_count)
{
	int	i;

	i = 0;
	while (r_count)
	{
		r_count = r_count >> 1;
		i++;
	}
	return (i);
}
