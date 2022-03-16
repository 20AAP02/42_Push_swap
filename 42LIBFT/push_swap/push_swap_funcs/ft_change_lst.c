/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:01:08 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:02:21 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_change_lst(char move, t_dlst **stack_a, t_dlst **stack_b)
{
	if (move == '1')
		ft_sa(*stack_a);
	else if (move == '2')
		ft_sb(*stack_b);
	else if (move == '3')
		ft_pa(stack_a, stack_b);
	else if (move == '4')
		ft_pb(stack_a, stack_b);
	else if (move == '5')
		ft_ra(stack_a);
	else if (move == '6')
		ft_rb(stack_b);
	else if (move == '7')
		ft_rra(stack_a);
	else if (move == '8')
		ft_rrb(stack_b);
}
