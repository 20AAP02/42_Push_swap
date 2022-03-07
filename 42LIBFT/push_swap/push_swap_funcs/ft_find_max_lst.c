#include <libft.h>
#include <push_swap.h>

int ft_find_max_lst(d_list *stack)
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