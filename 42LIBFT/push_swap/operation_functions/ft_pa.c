/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:40:13 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 16:40:14 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_pa(t_dlst **stack_a, t_dlst **stack_b)
{
	t_dlst	*mem;

	if (ft_lstsize_d_lst(*stack_b) < 1)
		return ;
	mem = (*stack_b)->next;
	ft_lstadd_front_d_lst(stack_a, *stack_b);
	*stack_b = mem;
}
