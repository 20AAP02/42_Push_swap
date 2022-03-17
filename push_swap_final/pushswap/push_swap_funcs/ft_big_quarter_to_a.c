/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bq.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:00:14 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:00:30 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_bq(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_p, int value)
{
	int	check;

	check = ((ft_lstsize_d_lst(*stack_a) + value) / 2);
	while (ft_lstsize_d_lst(*stack_b) > value / 4)
	{
		if (*((*stack_b)->content) >= check)
			ft_upd(sort_p, "3", stack_a, stack_b);
		else
			ft_upd(sort_p, "6", stack_a, stack_b);
	}
}
