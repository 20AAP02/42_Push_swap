#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// function to print linked list (uses printf)
void ft_print_linked_list(d_list *stack_a)
{
	while (stack_a)
	{
		ft_printf("%i\n", *(stack_a->content));
		stack_a = stack_a->next;
	}
}