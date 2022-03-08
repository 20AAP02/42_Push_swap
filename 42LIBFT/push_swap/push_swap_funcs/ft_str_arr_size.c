#include "../../42_libft/libft.h"
#include "../push_swap.h"

int ft_str_arr_size(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}