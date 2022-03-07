#include <libft.h>
#include <push_swap.h>

void ft_sortb_section(d_list **stack_a, d_list **stack_b, s_sort *sort_o)
{
	int step;
	int min;
	int max;
	int f_max;

	f_max = ft_find_max_lst(*stack_b);
	while (ft_lstsize_d_lst(*stack_b))
	{
		min = ft_find_min_pos_lst(*stack_b);
		max = ft_find_max_pos_lst(*stack_b);
		step = ft_calc_fastest_number(stack_b, min, max);
		// bring max to top by going up
		if (!step)
			while (ft_find_max_pos_lst(*stack_b))
				ft_update_sort_score(sort_o, "6", stack_a, stack_b);
		if (step == 1)
			while (ft_find_min_pos_lst(*stack_b))
				ft_update_sort_score(sort_o, "6", stack_a, stack_b);
		if (step == 2)
			while (ft_find_max_pos_lst(*stack_b))
				ft_update_sort_score(sort_o, "8", stack_a, stack_b);
		if (step == 3)
			while (ft_find_min_pos_lst(*stack_b))
				ft_update_sort_score(sort_o, "8", stack_a, stack_b);
		if (step == 1 || step == 3)
		{
			ft_update_sort_score(sort_o, "3", stack_a, stack_b);
			ft_update_sort_score(sort_o, "5", stack_a, stack_b);
		}
		if (step == 0 || step == 2)
			ft_update_sort_score(sort_o, "3", stack_a, stack_b);
	}
	while (f_max != *(ft_lstlast_d_lst(*stack_a)->content))
		ft_update_sort_score(sort_o, "5", stack_a, stack_b);
}