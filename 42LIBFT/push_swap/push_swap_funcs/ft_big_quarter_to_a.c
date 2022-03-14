#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void ft_big_quarter_to_a(d_list **stack_a, d_list **stack_b, s_sort *sort_p, int value)
{
	int check;

	check = ((ft_lstsize_d_lst(*stack_a) + value) / 2);
	while (ft_lstsize_d_lst(*stack_b) > value / 4)
	{
		if (*((*stack_b)->content) >= check)
			ft_update_sort_score(sort_p, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_p, "6", stack_a, stack_b);
	}
}
