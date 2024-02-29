#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//libs
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"

typedef struct s_stack
{
	struct s_list	*next;
	void			*content;
}	t_stack;

size_t stack_fill(char *args,  int argc, t_list *a);
int arg_val(char **argv);

#endif
