#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void ft_small_half_to_b(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_p, int value)
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