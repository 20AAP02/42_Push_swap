#include <libft.h>
#include <push_swap.h>

// sorting algrithm for lists of 50 numbers (function that devides the list in 2)
void ft_sort_stack7(d_list **stack_a, d_list **stack_b, s_sort *sort_7)
{
	int half;
	int check;

	check = 0;
	ft_make_range(stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_a) % 2)
		check = 1;
	half = ft_lstsize_d_lst(*stack_a) / 2;
	ft_small_half_to_b(stack_a, stack_b, sort_7, half);
	ft_sortb_section(stack_a, stack_b, sort_7);
	while (ft_lstsize_d_lst(*stack_a) != 0)
		ft_update_sort_score(sort_7, "4", stack_a, stack_b);
	ft_sortb_section(stack_a, stack_b, sort_7);
}
