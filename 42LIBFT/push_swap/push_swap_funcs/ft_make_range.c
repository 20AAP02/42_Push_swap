#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// simplify list of ints to [0, N]
void ft_make_range(t_dlst **stack_a, t_dlst **stack_b)
{
	t_dlst **stack_a_cpy;
	t_dlst *mem;
	int n;
	int i;

	stack_a_cpy = NULL;
	stack_a_cpy = ft_make_lst_cpy(stack_a_cpy, *stack_a);
	while (ft_lstsize_d_lst(*stack_a))
	{
		n = *((*stack_a_cpy)->content);
		mem = (*stack_a_cpy)->next;
		i = 0;
		while (mem)
		{
			if (*(mem->content) < n)
				i++;
			mem = mem->next;
		}
		*((*stack_a)->content) = i;
		ft_pb(stack_a, stack_b);
		ft_ra(stack_a_cpy);
	}
	while (ft_lstsize_d_lst(*stack_b))
		ft_pa(stack_a, stack_b);
	ft_lstclear_d_lst(stack_a_cpy);
}
