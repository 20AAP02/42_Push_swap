#include "../../42_libft/libft.h"
#include "../push_swap.h"

int ft_find_min_lst(d_list *stack)
{
	int min_value;

	min_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) < min_value)
			min_value = *(stack->content);
		stack = stack->next;
	}
	return (min_value);
}