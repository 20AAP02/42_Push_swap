/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:08:11 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 16:28:38 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

t_500	ft_block11(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half / 4)
	{
		if ((ex.half / 2) + 1 < ex.i)
			break ;
		if (*((*stack_b)->content) >= ((ex.half * 3) + (ex.half / 4)))
			ft_update_sort_score(sort_, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_, "6", stack_a, stack_b);
		ex.i++;
	}
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	while (*((*stack_a)->content) < ((ex.half * 3) + (ex.half / 2)))
		ft_update_sort_score(sort_, "4", stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	while (*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_, "4", stack_a, stack_b);
	return (ex);
}

t_500	ft_block12(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	int	j;

	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half / 4)
	{
		if ((ex.half / 2) + 1 < ex.i)
			break ;
		j = ((ex.half * 3) + (ex.half / 2) + (ex.half / 4));
		if (*((*stack_b)->content) >= j)
			ft_update_sort_score(sort_, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_, "6", stack_a, stack_b);
		ex.i++;
	}
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	while (*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_, "4", stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	return (ex);
}

void	ft_sort_stack10(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	t_500	ex;

	ex.i = 0;
	ex.half = 0;
	ft_make_range(stack_a, stack_b);
	ex = ft_block1(ex, stack_a, stack_b, sort_);
	ex = ft_block2(ex, stack_a, stack_b, sort_);
	ex = ft_block3(ex, stack_a, stack_b, sort_);
	ex = ft_block4(ex, stack_a, stack_b, sort_);
	ex = ft_block5(ex, stack_a, stack_b, sort_);
	ex = ft_block6(ex, stack_a, stack_b, sort_);
	ex = ft_block7(ex, stack_a, stack_b, sort_);
	ex = ft_block8(ex, stack_a, stack_b, sort_);
	ex = ft_block9(ex, stack_a, stack_b, sort_);
	ex = ft_block10(ex, stack_a, stack_b, sort_);
	ex = ft_block11(ex, stack_a, stack_b, sort_);
	ex = ft_block12(ex, stack_a, stack_b, sort_);
}
