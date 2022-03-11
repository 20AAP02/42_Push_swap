#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// function to apply move to stacks (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)
void ft_change_lst(char move, d_list **stack_a, d_list **stack_b)
{
	if (move == '1')
		ft_sa(*stack_a);
	else if (move == '2')
		ft_sb(*stack_b);
	else if (move == '3')
		ft_pa(stack_a, stack_b);
	else if (move == '4')
		ft_pb(stack_a, stack_b);
	else if (move == '5')
		ft_ra(stack_a);
	else if (move == '6')
		ft_rb(stack_b);
	else if (move == '7')
		ft_rra(stack_a);
	else if (move == '8')
		ft_rrb(stack_b);
}