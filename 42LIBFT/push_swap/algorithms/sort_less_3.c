#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// sort algrithm for lists of 3 numbers
void ft_sort_stack_less3(d_list **stack_a, d_list **stack_b, s_sort *sort_1)
{
	int mem1;
	int mem2;
	int mem3;

	if (ft_lstsize_d_lst(*stack_a) == 2)
		ft_update_sort_score(sort_1, "1", stack_a, stack_b);
	else if (ft_lstsize_d_lst(*stack_a) > 3)
		return ;
	else
	{
		mem1 = *((*stack_a)->content);
		mem2 = *((*stack_a)->next->content);
		mem3 = *((*stack_a)->next->next->content);

		if (mem1 > mem2 && mem1 < mem3)
			ft_update_sort_score(sort_1, "1", stack_a, stack_b);
		else if (mem1 > mem2 && mem1 > mem3 && mem2 > mem3)
			ft_update_sort_score(sort_1, "17", stack_a, stack_b);
		else if (mem1 > mem2 && mem1 > mem3 && mem2 < mem3)
			ft_update_sort_score(sort_1, "5", stack_a, stack_b);
		else if (mem1 < mem2 && mem1 < mem3 && mem2 > mem3)
			ft_update_sort_score(sort_1, "15", stack_a, stack_b);
		else if (mem1 < mem2 && mem1 > mem3)
			ft_update_sort_score(sort_1, "7", stack_a, stack_b);
	}
}