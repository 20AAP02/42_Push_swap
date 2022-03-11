#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

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
	printf("----- %i --------\n", ft_lstsize_d_lst(*stack_b));
	half = ft_lstsize_d_lst(*stack_b) / 2;
	ft_big_quarter_to_a(stack_a, stack_b, sort_8, half);
	ft_sortb_section(stack_a, stack_b, sort_8);

	// 3 quarters sorted

	while (*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_8, "4", stack_a, stack_b);
	ft_sortb_section(stack_a, stack_b, sort_8);
	//ft_print_linked_list(*stack_a);
}
// (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)
void ft_radix_sort(d_list **stack_a, d_list **stack_b, s_sort *sort_p)
{
	int i;
	int j;
	int num;
	int size;
	int max_num;
	int max_bits;

	ft_make_range(stack_a, stack_b);
	size = ft_lstsize_d_lst(*stack_a);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = *((*stack_a)->content);
			if (((num >> i)&1) == 1)
				ft_update_sort_score(sort_p, "5", stack_a, stack_b);
			else
				ft_update_sort_score(sort_p, "4", stack_a, stack_b);
			j++;
		}
		while (ft_lstsize_d_lst(*stack_b))
			ft_update_sort_score(sort_p, "3", stack_a, stack_b);
		i++;
	}
}