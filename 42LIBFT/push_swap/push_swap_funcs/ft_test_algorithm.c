#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// function to test algorithms whithout having to create a stack for each algorithm
void ft_test_algorithm(t_sort *sort_s, t_dlst **stack_a, void (*f)(t_dlst**, t_dlst**, t_sort*))
{
	t_dlst **stack_a_cpy;
	t_dlst **stack_b_cpy;

	stack_b_cpy = malloc(sizeof(t_dlst*));
	*stack_b_cpy = NULL;

	stack_a_cpy = NULL;
	stack_a_cpy = ft_make_lst_cpy(stack_a_cpy, *stack_a);
	(*f)(stack_a_cpy, stack_b_cpy, sort_s);

	ft_lstclear_d_lst(stack_a_cpy);
	free(stack_b_cpy);
}
