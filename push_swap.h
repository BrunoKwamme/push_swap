#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//libs
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
//# include "printf/libftprintf.h"

typedef struct s_stack
{
	struct s_list	*next;
	void			*content;
}	t_stack;

#endif
