/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:05:30 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/29 13:23:25 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	*arr_cat(long *array, int arg_len, char **splitted_args)
{
	int		i;
	int		new_arr_len;
	long	*new_array;

	i = 0;
	new_arr_len = 0;
	while (splitted_args[new_arr_len] != NULL)
		new_arr_len++;
	new_array = ft_calloc(sizeof(long), arg_len + new_arr_len);
	if (!new_array)
		return (NULL);
	while (i < arg_len)
	{
		new_array[i] = array[i];
		i++;
	}
	i = 0;
	while (i < new_arr_len)
	{
		new_array[new_arr_len] = ft_atol(splitted_args[i]);
		i++;
	}
	free(array);
	return (new_array);
}

long	*create_array(char **splitted_args)
{
	int		i;
	int		arg_len;
	long	*arg_arr;

	arg_arr = NULL;
	arg_len = 0;
	i = 0;
	while (splitted_args[arg_len] != NULL)
		arg_len++;
	arg_arr = ft_calloc(sizeof(long), arg_len);
	if (!arg_arr)
		return (NULL);
	while (arg_len > i)
	{
		arg_arr[i] = ft_atol(splitted_args[i]);
		i++;
	}
	return (arg_arr);
}

long	*mult_arg_array(char **argv, int argc)
{
	int			i;
	int			x;
	long		*array;

	i = 1;
	x = 0;
	array = ft_calloc(sizeof(long), (argc - 1));
	while (i <= (argc - 1))
	{
		array[x] = ft_atol_mult_arg(argv[i]);
		i++;
		x++;
	}
	return (array);
}

long	*array_management(long *arg_arr, int arg_len, char **splitted_args)
{
	arg_arr = arr_cat(arg_arr, arg_len, splitted_args);
	free_splitted_args(splitted_args);
	return (arg_arr);
}

long	*arg_into_array(char **argv, int argc)
{
	char	**splitted_args;
	long	*arg_arr;
	int		arg_len;
	int		i;

	splitted_args = NULL;
	arg_arr = NULL;
	arg_len = 0;
	i = 1;
	while (i <= (argc - 1))
	{
		splitted_args = ft_split(argv[i], ' ');
		if (arg_arr == NULL)
		{
			arg_arr = create_array(splitted_args);
			while (splitted_args[arg_len] != NULL)
				arg_len++;
		}
		else
			arg_arr = arr_cat(arg_arr, arg_len, splitted_args);
		free_splitted_args(splitted_args);
		i++;
	}
	return (arg_arr);
}
