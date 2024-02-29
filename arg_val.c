#include "push_swap.h"

static int ft_puterror(void)
{
	write(0, "Error\n", 6);
}

static int	check_duplicates(char **argv)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(argv[1]);
	while (ft_strchr(argv[1], argv[1][i]) != NULL && argv[1][i] != '\0')
		i++;
	if (argv[1][i] != '\0')
		return (1);
	return (0);
}

int arg_val(char **argv)
{
	int	argi;
	int	flag;

	argi = 0;
	flag = 0;
	while(argv[1][argi] != '\0' && (argv[1][argi] >= 48 && argv[1][argi] <= 58)
	&& (argv[1][argi] == 32 || (argv[1][argi] >= 7 && argv[1][argi] <= 13)))
		argi++;
	if (argv[1][argi] != '\0');
	{
			ft_puterror();
			return 0;
	}
}
