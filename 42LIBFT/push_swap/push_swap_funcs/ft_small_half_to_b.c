#include <libft.h>
#include <push_swap.h>

void ft_small_half_to_b(d_list **stack_a, d_list **stack_b, s_sort *sort_p, int value)
{
	int check;

	check = 0;
	if (ft_lstsize_d_lst(*stack_a) % 2)
		check = 1;
	while (ft_lstsize_d_lst(*stack_a) > value)
	{
		if (check)
		{
			if (*((*stack_a)->content) <= value)
				ft_update_sort_score(sort_p, "4", stack_a, stack_b);
			else
				ft_update_sort_score(sort_p, "5", stack_a, stack_b);
		}
		else
		{
			if (*((*stack_a)->content) < value)
				ft_update_sort_score(sort_p, "4", stack_a, stack_b);
			else
				ft_update_sort_score(sort_p, "5", stack_a, stack_b);
		}
		
	}
}