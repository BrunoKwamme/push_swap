/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:32 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/26 06:02:14 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//libs
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
//stack
typedef struct s_stack
{
	struct s_stack	*next;
	int			data;
	int			i;
}	t_stack;

//push_swap_utils
int	check_spaces(char c);
void ft_puterror(void);
int check_signal (char c);
long	ft_atol(const char *nptr);
int	stack_size(t_stack *stack);
//arg val
int	arr_val(int *array);
int arg_val(char **argv);
int	array_val(long *arr);
//create array
int arr_len(long *array);
long	*arg_into_array(char	**argv, int argc);
long	*create_array(char **splitted_args);
long	*arr_cat(long *array, int arg_len, char **splitted_args);
void free_splitted_args(char **splitted_args);
//create_stack
void	create_stack(t_stack **stack, long *arr, long *stack_i, int arr_len);
long	*stack_index(long *array, int arr_len);
int    is_stack_ordered(t_stack **stack_a);
int    binary_limit(int r_count);
void create_stack_b(t_stack **b);
//swap_move
void	sa(t_stack **a);
void	sb(t_stack **a);
void	ss(t_stack **a, t_stack **b);
//push_move
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//rotate_move
void	ra(t_stack **a);
void 	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
//reverse_move
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
//operations
void	three_nodes(t_stack **a);
void	five_nodes(t_stack **a, t_stack **b);
void    more_than_five(t_stack **stack_a, t_stack **stack_b);
void    order_by_radix(t_stack **stack_a, t_stack **stack_b, int ind);



#endif
