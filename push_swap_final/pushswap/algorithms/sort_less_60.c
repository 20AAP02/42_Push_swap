/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_60.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:29:14 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/17 16:00:46 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_sort_stack7(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_7)
{
	int	half;

	ft_make_range(stack_a, stack_b);
	half = ft_lstsize_d_lst(*stack_a) / 2;
	ft_s(stack_a, stack_b, sort_7, half);
	ft_sortb_section(stack_a, stack_b, sort_7);
	while (ft_lstsize_d_lst(*stack_a) != 0)
		ft_upd(sort_7, "4", stack_a, stack_b);
	ft_sortb_section(stack_a, stack_b, sort_7);
}
