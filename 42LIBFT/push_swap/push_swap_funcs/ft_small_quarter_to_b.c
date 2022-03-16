/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:06:35 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 21:01:05 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_sqb(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_p, int value)
{
	int	check;

	check = 0;
	if (ft_lstsize_d_lst(*stack_a) % 2)
		check = 1;
	if (check)
		while (*((*stack_a)->content) <= value)
			ft_upd_s(sort_p, "4", stack_a, stack_b);
	else
		while (*((*stack_a)->content) < value)
			ft_upd_s(sort_p, "4", stack_a, stack_b);
}
