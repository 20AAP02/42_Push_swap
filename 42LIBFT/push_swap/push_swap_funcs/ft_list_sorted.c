#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// Checker function (checks if stack_a is sorted)
int ft_list_sorted(t_dlst *stack)
{
	int i;

	i = 0;
	if (!stack)
		return (2);
	while (stack->next)
	{
		if (*(stack->content) > (*(stack->next->content) - 1))
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}