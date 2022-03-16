/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortb_section.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:06:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:42:53 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

typedef struct t_sortb
{
	int	step;
	int	min;
	int	max;
	int	f_max;
}	t_sortb;

void	ft_sortb_block(t_sortb e, t_dlst **stack_a, t_dlst **stack_b, t_sort *j)
{
	while (e.f_max != *(ft_lstlast_d_lst(*stack_a)->content))
		ft_upd_s(j, "5", stack_a, stack_b);
}

void	ft_sortb_section(t_dlst **stack_a, t_dlst **stack_b, t_sort *j)
{
	t_sortb	e;

	e.f_max = ft_find_max_lst(*stack_b);
	while (ft_lstsize_d_lst(*stack_b))
	{
		e.max = ft_find_max_pos_lst(*stack_b);
		e.step = ft_calc_fastest_number(stack_b, ft_mp_lst(*stack_b), e.max);
		if (!e.step)
			while (ft_find_max_pos_lst(*stack_b))
				ft_upd_s(j, "6", stack_a, stack_b);
		if (e.step == 1)
			while (ft_mp_lst(*stack_b))
				ft_upd_s(j, "6", stack_a, stack_b);
		if (e.step == 2)
			while (ft_find_max_pos_lst(*stack_b))
				ft_upd_s(j, "8", stack_a, stack_b);
		if (e.step == 3)
			while (ft_mp_lst(*stack_b))
				ft_upd_s(j, "8", stack_a, stack_b);
		if (e.step == 1 || e.step == 3)
			ft_upd_s(j, "35", stack_a, stack_b);
		if (e.step == 0 || e.step == 2)
			ft_upd_s(j, "3", stack_a, stack_b);
	}
	ft_sortb_block(e, stack_a, stack_b, j);
}
