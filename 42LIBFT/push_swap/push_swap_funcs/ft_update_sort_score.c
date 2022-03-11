#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// function to update sort score
void ft_update_sort_score(s_sort *sort_s, char *move, d_list **stack_a, d_list **stack_b)
{
	char *mem;

	if (!(sort_s->moves_str))
		sort_s->moves_str = ft_strjoin(move, "");
	else
	{
		mem = ft_strjoin(sort_s->moves_str, move);
		free(sort_s->moves_str);
		sort_s->moves_str = mem;
	}
	while (*move)
	{
		sort_s->n_moves += 1;
		ft_change_lst(*move, stack_a, stack_b);
		move++;
	}
}