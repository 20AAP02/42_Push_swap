#include "../../42_libft/libft.h"
#include "../push_swap.h"

void ft_free_sort_scores(s_sort **sort_scores)
{
	s_sort **ex;

	ex = sort_scores;
	while (*sort_scores)
	{
		if ((*sort_scores)->moves_str)
			free((*sort_scores)->moves_str);
		free(*sort_scores);
		sort_scores++;
	}
	free(ex);	
}
