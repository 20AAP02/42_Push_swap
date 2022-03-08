#include "../../42_libft/libft.h"
#include "../push_swap.h"

void ft_small_quarter_to_b(d_list **stack_a, d_list **stack_b, s_sort *sort_p, int value)
{
	int check;

	check = 0;
	if (ft_lstsize_d_lst(*stack_a) % 2)
		check = 1;
	
	if (check)
		while (*((*stack_a)->content) <= value)
			ft_update_sort_score(sort_p, "4", stack_a, stack_b);
	else
		while (*((*stack_a)->content) < value)
			ft_update_sort_score(sort_p, "4", stack_a, stack_b);
}