/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:05:30 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/25 19:34:03 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int arr_len(long *array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

long	*arr_cat(long *dest, long *src)
{
	int	dest_len;
	int	src_len;
	int	i;
	long	*new_array;

	i = 0;
	dest_len = (arr_len(dest));
	src_len = (arr_len(src));
	new_array = ft_calloc(sizeof(long), src_len + dest_len + 1);
	if (!new_array)
		return(NULL);
	while (i < dest_len)
	{
		new_array[i] = dest[i];
		i++;
	}
	i = 0;
	while (i < src_len)
	{
		new_array[dest_len] = src[i];
		i++;
		dest_len++;
	}
	free(dest);
	free(src);
	return (new_array);
}

long	*create_array(char **splitted_args)
{
	int	i;
	long	l;
	int	arg_len;
	long	*arg_arr;

	arg_arr = NULL;
	arg_len = 0;
	i = 0;
	while (splitted_args[arg_len] != NULL)
		arg_len++;
	arg_arr = ft_calloc((arg_len + 1), sizeof(long));
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
	int		i;

	splitted_args = NULL;
	arr_to_cat = NULL;
	arg_arr = NULL;
	i = 1;
	while (i <= (argc - 1))
	{
		splitted_args = ft_split(argv[i], ' ');
		if (arg_arr == NULL)
			arg_arr = create_array(splitted_args);
		else
		{
			arr_to_cat = create_array(splitted_args);
			arg_arr = arr_cat(arg_arr, arr_to_cat);
		}
		free_splitted_args(splitted_args);
		i++;
	}
	return (arg_arr);
}
