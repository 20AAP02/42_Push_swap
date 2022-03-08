#include "../../42_libft/libft.h"
#include "../push_swap.h"

// function to test algorithms whithout having to create a stack for each algorithm
void ft_test_algorithm(s_sort *sort_s, d_list **stack_a, void (*f)(d_list**, d_list**, s_sort*))
{
	d_list **stack_a_cpy;
	d_list **stack_b_cpy;

	stack_b_cpy = malloc(sizeof(d_list*));
	*stack_b_cpy = NULL;

	stack_a_cpy = NULL;
	stack_a_cpy = ft_make_lst_cpy(stack_a_cpy, *stack_a);
	(*f)(stack_a_cpy, stack_b_cpy, sort_s);

	ft_lstclear_d_lst(stack_a_cpy);
	free(stack_b_cpy);
}
