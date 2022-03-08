#include "../../42_libft/libft.h"
#include "../push_swap.h"

// Make a copy of a linked list
d_list **ft_make_lst_cpy(d_list **stack_a_cpy, d_list *stack_a_orig)
{
	int *value;

	// Creating stack_a & stack_b copies
	stack_a_cpy = malloc(sizeof(d_list*));
	*stack_a_cpy = NULL;

	while (stack_a_orig)
	{
		value = malloc(sizeof(int));
		*value = *(stack_a_orig->content);
		ft_lstadd_back_d_lst(stack_a_cpy, ft_lstnew_d_lst(value));
		stack_a_orig = stack_a_orig->next;
	}

	return (stack_a_cpy);
}