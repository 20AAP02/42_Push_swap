#include "../../42_libft/libft.h"
#include "../push_swap.h"

// Checker function (checks if stack_a is sorted)
int ft_list_sorted(d_list *stack, int j)
{
	int i;

	i = 0;
	if (!stack)
		return (2);
	if (j)
		while (*(stack->content) != 0)
			stack = stack->next;
	while (stack->next)
	{
		if (*(stack->content) != (*(stack->next->content) - 1))
		{
			if (j)
				printf("-- ( %i, %i ) --\n", *(stack->content), *(stack->next->content));
			return (0);
		}
		stack = stack->next;
		i++;
	}
	return (1);
}