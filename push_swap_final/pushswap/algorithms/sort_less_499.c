/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_499.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:54:45 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/17 16:00:46 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

typedef struct t_radix
{
	int	i;
	int	size;
	int	max_num;
	int	max_bits;
}	t_radix;

void	ft_sort_stack8(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_8)
{
	int	half;

	ft_make_range(stack_a, stack_b);
	half = ft_lstsize_d_lst(*stack_a) / 2;
	ft_s(stack_a, stack_b, sort_8, half);
	half = ft_lstsize_d_lst(*stack_b) / 2;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if (*((*stack_b)->content) >= half)
			ft_upd(sort_8, "3", stack_a, stack_b);
		else
			ft_upd(sort_8, "6", stack_a, stack_b);
	}
	ft_sortb_section(stack_a, stack_b, sort_8);
	half = ft_lstsize_d_lst(*stack_a) / 2;
	ft_sqb(stack_a, stack_b, sort_8, half);
	ft_sortb_section(stack_a, stack_b, sort_8);
	half = ft_lstsize_d_lst(*stack_a);
	while (*((*stack_a)->content) != 0)
		ft_upd(sort_8, "4", stack_a, stack_b);
	ft_bq(stack_a, stack_b, sort_8, half);
	ft_sortb_section(stack_a, stack_b, sort_8);
	while (*((*stack_a)->content) != 0)
		ft_upd(sort_8, "4", stack_a, stack_b);
	ft_sortb_section(stack_a, stack_b, sort_8);
}

void	ft_radix_sort(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_p)
{
	t_radix	ex;

	ft_make_range(stack_a, stack_b);
	ex.size = ft_lstsize_d_lst(*stack_a);
	ex.max_num = ex.size - 1;
	ex.max_bits = 0;
	while ((ex.max_num >> ex.max_bits) != 0)
		ex.max_bits++;
	ex.i = -1;
	while (++ex.i < ex.max_bits)
	{
		ex.max_num = -1;
		while (++ex.max_num < ex.size)
		{
			if (((*((*stack_a)->content) >> ex.i) & 1) == 1)
				ft_upd(sort_p, "5", stack_a, stack_b);
			else
				ft_upd(sort_p, "4", stack_a, stack_b);
		}
		while (ft_lstsize_d_lst(*stack_b))
			ft_upd(sort_p, "3", stack_a, stack_b);
	}
}
