#include "../../42_libft/libft.h"
#include "../push_swap.h"

// free split argv[1] strings
void ft_free_split(char **mem)
{
	int i;

	i = -1;
	while (mem[++i])
		free(mem[i]);
	free(mem);
}
