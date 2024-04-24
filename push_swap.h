/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:32 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/24 02:56:10 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//libs
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
//stack
typedef struct s_stack
{
	struct s_list	*next;
	void			*content;
	int				i;
}	t_stack;

size_t stack_fill(char *args,  int argc, t_list *a);
long	ft_atol(const char *nptr);
int	*arr_cat(int *dest, int *src);
int	check_dup_num(int *arr);
int	arr_val(int *array);
int	check_overflow(int *arr);
int arr_len(int *array);
int arg_val(char **argv);
int	check_spaces(char c);
void ft_puterror(void);

#endif
