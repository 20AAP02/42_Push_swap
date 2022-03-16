#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// function to collect the parameters of the stack_a
t_dlst **ft_collect_integers(int argc, char **argv, int k)
{
	t_dlst **stack_a;
	int *value;
	int i;

	stack_a = malloc(sizeof(t_dlst*));
	*stack_a = NULL;
	i = k;
	while ((k == 1 && i < argc) || (k == 0 && argv[i]))
	{
		value = malloc(sizeof(int));
		*value = ft_atoi_dbl(argv[i++]);
		ft_lstadd_back_d_lst(stack_a, ft_lstnew_d_lst(value));
	}
	return (stack_a);
}