/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:33:43 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:42:53 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../../ft_printf/ft_printf.h"

t_500	ft_block6(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	int	j;

	while (*((*stack_a)->content) < (ex.half + (ex.half / 2)))
		ft_upd_s(sort_, "4", stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	ex.half = ft_lstsize_d_lst(*stack_a);
	while (*((*stack_a)->content) < (ex.half / 2))
		ft_upd_s(sort_, "4", stack_a, stack_b);
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > (ex.half / 16))
	{
		if ((ex.half / 8) + 1 < ex.i)
			break ;
		j = ((ex.half / 16) + (ex.half / 4) + (ex.half / 8) + 1);
		if (*((*stack_b)->content) >= j)
			ft_upd_s(sort_, "3", stack_a, stack_b);
		else
			ft_upd_s(sort_, "6", stack_a, stack_b);
		ex.i++;
	}
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	return (ex);
}

t_500	ft_block7(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	while (*((*stack_a)->content) < (ex.half / 2))
		ft_upd_s(sort_, "4", stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	while (*((*stack_a)->content) != 0)
		ft_upd_s(sort_, "4", stack_a, stack_b);
	ex.half = ft_lstsize_d_lst(*stack_b);
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half / 2)
	{
		if (ex.half + 1 < ex.i)
			break ;
		if (*((*stack_b)->content) >= (ex.half + (ex.half / 2)))
			ft_upd_s(sort_, "3", stack_a, stack_b);
		else
			ft_upd_s(sort_, "6", stack_a, stack_b);
		ex.i++;
	}
	return (ex);
}

t_500	ft_block8(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	ex.half = ft_lstsize_d_lst(*stack_b);
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half / 2)
	{
		if (ex.half + 1 < ex.i++)
			break ;
		if (*((*stack_b)->content) >= ((ex.half * 2) + (ex.half / 2)))
			ft_upd_s(sort_, "3", stack_a, stack_b);
		else
			ft_upd_s(sort_, "6", stack_a, stack_b);
	}
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half / 4)
	{
		if ((ex.half / 2) + 1 < ex.i++)
			break ;
		if (*((*stack_b)->content) >= ((ex.half * 2) + (ex.half / 4) + 1))
			ft_upd_s(sort_, "3", stack_a, stack_b);
		else
			ft_upd_s(sort_, "6", stack_a, stack_b);
	}
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	return (ex);
}

t_500	ft_block9(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	int	j;

	while (*((*stack_a)->content) < ((ex.half * 2) + (ex.half / 2)))
		ft_upd_s(sort_, "4", stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	while (*((*stack_a)->content) < (ex.half * 3))
		ft_upd_s(sort_, "4", stack_a, stack_b);
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half / 4)
	{
		if ((ex.half / 2) + 1 < ex.i)
			break ;
		j = ((ex.half * 2) + (ex.half / 4) + (ex.half / 2));
		if (*((*stack_b)->content) >= j)
			ft_upd_s(sort_, "3", stack_a, stack_b);
		else
			ft_upd_s(sort_, "6", stack_a, stack_b);
		ex.i++;
	}
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	return (ex);
}

t_500	ft_block10(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	while (*((*stack_a)->content) < (ex.half * 3))
		ft_upd_s(sort_, "4", stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	while (*((*stack_a)->content) != 0)
		ft_upd_s(sort_, "4", stack_a, stack_b);
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half / 2)
	{
		if (ex.half + 1 < ex.i)
			break ;
		if (*((*stack_b)->content) >= ((ex.half * 3) + (ex.half / 2)))
			ft_upd_s(sort_, "3", stack_a, stack_b);
		else
			ft_upd_s(sort_, "6", stack_a, stack_b);
		ex.i++;
	}
	return (ex);
}
