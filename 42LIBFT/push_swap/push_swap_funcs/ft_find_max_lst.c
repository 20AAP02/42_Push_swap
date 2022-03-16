#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

int ft_find_max_lst(t_dlst *stack)
{
	int max_value;

	max_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) > max_value)
			max_value = *(stack->content);
		stack = stack->next;
	}
	return (max_value);
}