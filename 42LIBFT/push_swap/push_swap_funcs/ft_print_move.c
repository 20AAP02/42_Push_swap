#include "../../42_libft/libft.h"
#include "../push_swap.h"

void ft_print_move(char a)
{
	if (a == '1')
		printf("sa\n");
	else if (a == '2')
		printf("sb\n");
	else if (a == 'a')
		printf("ss\n");
	else if (a == '3')
		printf("pa\n");
	else if (a == '4')
		printf("pb\n");
	else if (a == '5')
		printf("ra\n");
	else if (a == '6')
		printf("rb\n");
	else if (a == 'b')
		printf("rr\n");
	else if (a == '7')
		printf("rra\n");
	else if (a == '8')
		printf("rrb\n");
	else if (a == 'c')
		printf("rrr\n");
}
