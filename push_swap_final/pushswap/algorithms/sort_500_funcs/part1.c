/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:29:55 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/17 16:00:46 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../../../ft_printf/ft_printf.h"

t_500	ft_block1(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	ex.half = ft_lstsize_d_lst(*stack_a) / 2;
	while (ft_lstsize_d_lst(*stack_a) > ex.half)
	{
		if ((ex.half * 2) + 1 < ex.i)
			break ;
		if (*((*stack_a)->content) < ex.half)
			ft_upd(sort_, "4", stack_a, stack_b);
		else
			ft_upd(sort_, "5", stack_a, stack_b);
		ex.i++;
	}
	ex.half = ft_lstsize_d_lst(*stack_b) / 2;
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half)
	{
		if ((ex.half * 2) + 1 < ex.i)
			break ;
		if (*((*stack_b)->content) >= ex.half)
			ft_upd(sort_, "3", stack_a, stack_b);
		else
			ft_upd(sort_, "6", stack_a, stack_b);
		ex.i++;
	}
	return (ex);
}

t_500	ft_block2(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	ex.half = ft_lstsize_d_lst(*stack_b) / 2;
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half)
	{
		if ((ex.half * 2) + 1 < ex.i++)
			break ;
		if (*((*stack_b)->content) >= ex.half)
			ft_upd(sort_, "3", stack_a, stack_b);
		else
			ft_upd(sort_, "6", stack_a, stack_b);
	}
	ex.half = ft_lstsize_d_lst(*stack_b) / 2;
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half)
	{
		if ((ex.half * 2) + 1 < ex.i++)
			break ;
		if (*((*stack_b)->content) >= ex.half)
			ft_upd(sort_, "3", stack_a, stack_b);
		else
			ft_upd(sort_, "6", stack_a, stack_b);
	}
	return (ex);
}

t_500	ft_block3(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	ex.half = ft_lstsize_d_lst(*stack_a) / 8;
	while (*((*stack_a)->content) < ex.half)
		ft_upd(sort_, "4", stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	ex.half = ft_lstsize_d_lst(*stack_a) / 4;
	while (*((*stack_a)->content) < ex.half)
		ft_upd(sort_, "4", stack_a, stack_b);
	ex.half = ft_lstsize_d_lst(*stack_b) / 2;
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > ex.half)
	{
		if ((ex.half * 2) + 1 < ex.i)
			break ;
		if (*((*stack_b)->content) >= (ex.half * 3))
			ft_upd(sort_, "3", stack_a, stack_b);
		else
			ft_upd(sort_, "6", stack_a, stack_b);
		ex.i++;
	}
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	return (ex);
}

t_500	ft_block4(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	ex.half = ft_lstsize_d_lst(*stack_a) / 4;
	while (*((*stack_a)->content) < ex.half)
		ft_upd(sort_, "4", stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	ex.half = ft_lstsize_d_lst(*stack_a) / 2;
	while (*((*stack_a)->content) < ex.half)
		ft_upd(sort_, "4", stack_a, stack_b);
	return (ex);
}

t_500	ft_block5(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_)
{
	ex.half = ft_lstsize_d_lst(*stack_b);
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > (ex.half / 2))
	{
		if (ex.half < ex.i++)
			break ;
		if (*((*stack_b)->content) >= (ex.half + (ex.half / 2)))
			ft_upd(sort_, "3", stack_a, stack_b);
		else
			ft_upd(sort_, "6", stack_a, stack_b);
	}
	ex.i = 0;
	while (ft_lstsize_d_lst(*stack_b) > (ex.half / 4))
	{
		if ((ex.half / 2) + 1 < ex.i++)
			break ;
		if (*((*stack_b)->content) >= (ex.half + (ex.half / 4)))
			ft_upd(sort_, "3", stack_a, stack_b);
		else
			ft_upd(sort_, "6", stack_a, stack_b);
	}
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_);
	return (ex);
}
