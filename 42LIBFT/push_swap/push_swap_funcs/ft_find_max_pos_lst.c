#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

int ft_find_max_pos_lst(t_dlst *stack)
{
	int i;
	int j;
	int max_value;

	i = 0;
	j = 0;
	max_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) > max_value)
		{
			max_value = *(stack->content);
			j = i;
		}
		i++;
		stack = stack->next;
	}
	return (j);
}
