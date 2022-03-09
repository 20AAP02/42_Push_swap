#include "42_libft/libft.h"
#include "push_swap/push_swap.h"

// (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)
// gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg
int main (int argc, char **argv)
{
	s_sort **sort_scores;
	int x;

	d_list **stack_a;
	char **mem;
	// Checking for parameters errors (1 - there are non integers) (2 - bigger than integer) (3 - to many arguments) (4 - there are duplicates)
	if (ft_check_parameters(argc, argv, 0) && ft_check_parameters(argc, argv, 0) != 5)
		return (printf("error\n"));
	if (ft_check_parameters(argc, argv, 0) == 5)
		mem = ft_split(argv[1], ' ');
	if (ft_check_parameters(argc, argv, 0) == 5 && ft_check_parameters(argc, mem, 1))
	{
		ft_free_split(mem);
		return (printf("error\n"));
	}
	if (ft_check_parameters(argc, argv, 0) == 5)
		stack_a = ft_collect_integers(argc, mem, 0);
	else
		stack_a = ft_collect_integers(argc, argv, 1);

	// malloc for sort_scores array
	sort_scores = malloc(sizeof(s_sort*) * 2);
	sort_scores[1] = NULL;

	// initialising sort_scores
	x = 0;
	while (x < 1)
	{
		sort_scores[x] = malloc(sizeof(s_sort));
		(sort_scores[x])->n_moves = 0;
		(sort_scores[x])->moves_str = NULL;
		x++;
	}
	
	if (!ft_list_sorted(*stack_a))
	{
		if (ft_lstsize_d_lst(*stack_a) <= 3)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack_less3);
		else if (ft_lstsize_d_lst(*stack_a) < 40)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack_less5);
		else if (ft_lstsize_d_lst(*stack_a) <= 60)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack7);
		else if (ft_lstsize_d_lst(*stack_a) <= 499)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack8);
		else if (ft_lstsize_d_lst(*stack_a) == 500)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack10);
	}
	if (!ft_list_sorted(*stack_a))
	{
		x = 0;
		while (x < 1)
		{
			if (ft_count_dmoves(sort_scores[x]->moves_str))
				sort_scores[x]->moves_str = ft_edit_movestr(ft_count_dmoves(sort_scores[x]->moves_str), sort_scores[x]->moves_str);
			(sort_scores[x])->n_moves = ft_strlen(sort_scores[x]->moves_str);
			x++;
		}
		x = 0;
		while (sort_scores[0]->moves_str[x])
		{
			ft_print_move(sort_scores[0]->moves_str[x]);
			x++;
		}
	}
	
	if (ft_check_parameters(argc, argv, 0) == 5)
		ft_free_split(mem);
	ft_lstclear_d_lst(stack_a);

	// free sort_scores
	ft_free_sort_scores(sort_scores);

	return (0);
}

// limits
// 3 digits - (max: 3)
// 5 digits - (max: 12)
// 100 digits - (max: 700)
// 500 digits - (max: 5500)