/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:36:03 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/21 17:17:57 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_spaces(char c)
{
	if (c == 32 || (c >= 7 && c <= 13))
		return (0);
	return (1);
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

int check_signal (char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	*argi(char **splitted_args)
{
	int	i;
	int	num_len;
	int	*arg_arr;

	num_len = 0;
	i = 0;
	while (splitted_args[num_len] != '\0')
		num_len++;
	while (splitted_args[i] != '\0')
	{
		ft_atol (*splitted_args[i]);
		arg_arr = malloc()

	}
}

int	check_numbers(char	*argv, int argc)
{
	char	**splitted_args;
	int		*arg_arr;
	int		i;

	i = 0;
	while (i < (argc - 1))
	{
		splitted_args = ft_split(argv[i], ' ');
		if (arg_arr == NULL)
			arg_arr = argi(splitted_args);
		else
			ft_memcpy(arg_arr, argi(splitted_args), ft_strlen(splitted_args[i]));
		i++;
	}
}

int main (void)
{
	#include<limits.h>
	#include<stdio.h>
	char *x = "2147483649";
	printf("%li", atol(x));
}
