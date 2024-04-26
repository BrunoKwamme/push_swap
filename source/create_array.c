/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:05:30 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/26 06:34:33 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	*arr_cat(long *array, int arg_len, char **splitted_args)
{
	int	i;
	int	new_arr_len;
	long	*new_array;

	i = 0;
	new_arr_len = 0;
	while (splitted_args[new_arr_len] != NULL)
		new_arr_len++;
	new_array = ft_calloc(sizeof(long), arg_len + new_arr_len);
	if (!new_array)
		return(NULL);
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
	int	i;
	int arg_len;
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

void free_splitted_args(char **splitted_args)
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

long	*arg_into_array(char	**argv, int argc)
{
	char	**splitted_args;
	long		*arr_to_cat;
	long		*arg_arr;
	int		arg_len;
	int		i;

	splitted_args = NULL;
	arr_to_cat = NULL;
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
		{
			arr_to_cat = create_array(splitted_args);
			arg_arr = arr_cat(arg_arr, arg_len, splitted_args);
		}
		free_splitted_args(splitted_args);
		i++;
	}
	return (arg_arr);
}

