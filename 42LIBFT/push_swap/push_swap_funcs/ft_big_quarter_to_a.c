#include <libft.h>
#include <push_swap.h>

void ft_big_quarter_to_a(d_list **stack_a, d_list **stack_b, s_sort *sort_p, int value)
{
	int check;

	check = 1;
	if (ft_lstsize_d_lst(*stack_a) % 2)
		check = 0;
	if (check)
	{
		while (ft_lstsize_d_lst(*stack_b) > value)
		{
			if (*((*stack_b)->content) >= (value * 3))
				ft_update_sort_score(sort_p, "3", stack_a, stack_b);
			else
				ft_update_sort_score(sort_p, "6", stack_a, stack_b);
		}
	}
	else
	{
		while (ft_lstsize_d_lst(*stack_b) > value)
		{
			if (*((*stack_b)->content) > (value * 3))
				ft_update_sort_score(sort_p, "3", stack_a, stack_b);
			else
				ft_update_sort_score(sort_p, "6", stack_a, stack_b);
		}
	}
}
