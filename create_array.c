/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:05:30 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/24 02:56:18 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_val(int *array)
{
	if (check_overflow(array) == 1 || check_dup_num(array) == 1)
		return (1);
	return (0);
}

int arr_len(int *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
		i++;
	return (i);
}

int	*arr_cat(int *dest, int *src)
{
	int	dest_len;
	int	src_len;
	int	i;
	int	*new_array;

	i = 0;
	dest_len = (arr_len(dest));
	src_len = (arr_len(src));
	new_array = ft_calloc(sizeof(int), src_len + dest_len + 1);
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

int	*create_array(char **splitted_args)
{
	int	i;
	int	arg_len;
	int	*arg_arr;

	arg_arr = NULL;
	arg_len = 0;
	i = 0;
	while (splitted_args[arg_len] != NULL)
		arg_len++;
	arg_arr = malloc((arg_len + 1) * sizeof(int));
	if (!arg_arr)
		return (NULL);
	while (arg_len > i)
	{
		arg_arr[i] = ft_atol(splitted_args[i]);
		i++;
	}
	return (arg_arr);
}

int	*arg_into_array(char	**argv, int argc)
{
	char	**splitted_args;
	int		*arr_to_cat;
	int		*arg_arr;
	int		i;

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
		free(splitted_args);
		i++;
	}
	return (arg_arr);
}

int main (int argc, char **argv)
{
	int	i;
	int	*arr;

	arr = arg_into_array(argv, argc);
	i = 0;
	while (i < 4)
	{
		ft_printf("%i", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
