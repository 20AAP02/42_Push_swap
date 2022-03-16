#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

int ft_calc_fastest_number(t_dlst **stack_b, int min, int max)
{
	int *arr;
	int i;
	int fast;

	arr = malloc(sizeof(int) * 4);
	arr[0] = 0 + max;
	arr[1] = 0 + min;
	arr[2] = ft_lstsize_d_lst(*stack_b) - max;
	arr[3] = ft_lstsize_d_lst(*stack_b) - min;
	i = 1;
	fast = 0;
	while (i < 4)
	{
		if (arr[i] < arr[fast])
			fast = i;
		i++;
	}
	free(arr);
	return (fast);
}
