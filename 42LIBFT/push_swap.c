/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:55:44 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/17 10:55:04 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_libft/libft.h"
#include "push_swap/push_swap.h"
#include "ft_printf/ft_printf.h"
// gcc push_swap.c libft.a && arg=$(python3 ../rando.py 300);
//./a.out $arg | ./checker_Mac $arg && ./a.out $arg | wc -l
void	ft_block_1(t_sort **sort_scores, t_dlst **stack_a, int x, char *str)
{
	if (!ft_list_sorted(*stack_a))
	{
		if (ft_lstsize_d_lst(*stack_a) <= 3)
			ft_k(sort_scores[0], stack_a, ft_sort_stack_less3);
		else if (ft_lstsize_d_lst(*stack_a) < 40)
			ft_k(sort_scores[0], stack_a, ft_sort_stack_less5);
		else if (ft_lstsize_d_lst(*stack_a) <= 60)
			ft_k(sort_scores[0], stack_a, ft_sort_stack7);
		else if (ft_lstsize_d_lst(*stack_a) <= 100)
			ft_k(sort_scores[0], stack_a, ft_sort_stack8);
		else if (ft_lstsize_d_lst(*stack_a) <= 499)
			ft_k(sort_scores[0], stack_a, ft_radix_sort);
		else if (ft_lstsize_d_lst(*stack_a) == 500)
			ft_k(sort_scores[0], stack_a, ft_sort_stack10);
		else if (ft_lstsize_d_lst(*stack_a) > 500)
			ft_k(sort_scores[0], stack_a, ft_radix_sort);
	}
	str = sort_scores[0]->moves_str;
	if (!ft_list_sorted(*stack_a) && ft_count_dmoves(str))
		sort_scores[0]->moves_str = ft_edit_movestr(ft_count_dmoves(str), str);
	if (!ft_list_sorted(*stack_a))
		while (sort_scores[0]->moves_str[x])
			ft_print_move(sort_scores[0]->moves_str[x++]);
}

void	ft_block_2(int argc, char **argv, t_dlst **stack_a, char **mem)
{
	if (ft_check_parameters(argc, argv, 0) == 5)
		ft_free_split(mem);
	ft_lstclear_d_lst(stack_a);
}

void	ft_block_3(t_sort **sort_scores)
{
	sort_scores[1] = NULL;
	sort_scores[0] = malloc(sizeof(t_sort));
	(sort_scores[0])->n_moves = 0;
	(sort_scores[0])->moves_str = NULL;
}

int	main(int argc, char **argv)
{
	t_sort	**sort_scores;
	int		x;
	t_dlst	**stack_a;
	char	**mem;

	if (ft_check_parameters(argc, argv, 0))
		if (ft_check_parameters(argc, argv, 0) != 5)
			return (ft_printf("error\n"));
	if (ft_check_parameters(argc, argv, 0) == 5)
		mem = ft_split(argv[1], ' ');
	if (ft_check_parameters(argc, argv, 0) == 5)
		if (ft_check_parameters(argc, mem, 1))
			return (ft_free_split(mem) + ft_printf("error\n"));
	if (ft_check_parameters(argc, argv, 0) == 5)
		stack_a = ft_collect_integers(argc, mem, 0);
	else
		stack_a = ft_collect_integers(argc, argv, 1);
	sort_scores = malloc(sizeof(t_sort *) * 2);
	ft_block_3(sort_scores);
	ft_block_1(sort_scores, stack_a, 0, "");
	ft_block_2(argc, argv, stack_a, mem);
	ft_free_sort_scores(sort_scores);
	return (0);
}
