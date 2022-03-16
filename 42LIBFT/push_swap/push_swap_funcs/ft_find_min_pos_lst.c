#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// function to find position of the minimum number of the stack
int ft_find_min_pos_lst(t_dlst *stack)
{
	int i;
	int j;
	int min_value;

	i = 0;
	j = 0;
	min_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) < min_value)
		{
			min_value = *(stack->content);
			j = i;
		}
		i++;
		stack = stack->next;
	}
	return (j);
}