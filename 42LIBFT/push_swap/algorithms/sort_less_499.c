#include "../../42_libft/libft.h"
#include "../push_swap.h"

// sorting algorithm for lists of 100 numbers (function that devides the list in 4)
void ft_sort_stack8(d_list **stack_a, d_list **stack_b, s_sort *sort_8)
{
	int half;

	ft_make_range(stack_a, stack_b);
	half = ft_lstsize_d_lst(*stack_a) / 2;
	ft_small_half_to_b(stack_a, stack_b, sort_8, half);
	half = ft_lstsize_d_lst(*stack_b) / 2;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if (*((*stack_b)->content) >= half)
			ft_update_sort_score(sort_8, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_8, "6", stack_a, stack_b);
	}
	ft_sortb_section(stack_a, stack_b, sort_8);

	// quarter sorted

	half = ft_lstsize_d_lst(*stack_a) / 2;
	ft_small_quarter_to_b(stack_a, stack_b, sort_8, half);
	ft_sortb_section(stack_a, stack_b, sort_8);

	// half sorted

	while (*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_8, "4", stack_a, stack_b);
	half = ft_lstsize_d_lst(*stack_b) / 2;
	ft_big_quarter_to_a(stack_a, stack_b, sort_8, half);
	ft_sortb_section(stack_a, stack_b, sort_8);

	// 3 quarters sorted

	while (*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_8, "4", stack_a, stack_b);
	ft_sortb_section(stack_a, stack_b, sort_8);
}
