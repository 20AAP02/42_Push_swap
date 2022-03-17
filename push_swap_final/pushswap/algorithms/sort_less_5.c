/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:07:32 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/17 16:00:46 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// sort algrithm for lists of 5 numbers
void	ft_sort_stack_less5(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_2)
{
	int	pos;

	if (ft_list_sorted(*stack_a))
		return ;
	while (ft_lstsize_d_lst(*stack_a) > 3)
	{
		pos = ft_mp_lst(*stack_a);
		if (pos <= (ft_lstsize_d_lst(*stack_a) / 2))
			while (ft_mp_lst(*stack_a) != 0)
				ft_upd(sort_2, "5", stack_a, stack_a);
		else
			while (ft_mp_lst(*stack_a) != 0)
				ft_upd(sort_2, "7", stack_a, stack_a);
		ft_upd(sort_2, "4", stack_a, stack_b);
	}
	ft_sort_stack_less3(stack_a, stack_b, sort_2);
	while (ft_lstsize_d_lst(*stack_b))
		ft_upd(sort_2, "3", stack_a, stack_b);
}
