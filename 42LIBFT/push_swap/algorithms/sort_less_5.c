#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// sort algrithm for lists of 5 numbers
void ft_sort_stack_less5(d_list **stack_a, d_list **stack_b, s_sort *sort_2)
{
	int pos;

	if (ft_list_sorted(*stack_a))
		return ;
	while (ft_lstsize_d_lst(*stack_a) > 3)
	{
		pos = ft_find_min_pos_lst(*stack_a);
		if (pos <= (ft_lstsize_d_lst(*stack_a) / 2))
			while (ft_find_min_pos_lst(*stack_a) != 0)
				ft_update_sort_score(sort_2, "5", stack_a, stack_a);
		else
			while (ft_find_min_pos_lst(*stack_a) != 0)
				ft_update_sort_score(sort_2, "7", stack_a, stack_a);
		ft_update_sort_score(sort_2, "4", stack_a, stack_b);
	}
	ft_sort_stack_less3(stack_a, stack_b, sort_2);
	while (ft_lstsize_d_lst(*stack_b))
		ft_update_sort_score(sort_2, "3", stack_a, stack_b);
}