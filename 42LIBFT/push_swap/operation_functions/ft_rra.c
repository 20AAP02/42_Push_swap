/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:41:47 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 16:41:48 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_rra(t_dlst **stack)
{
	t_dlst	*mem;
	int		value_c2;
	int		value_c1;

	if (ft_lstsize_d_lst(*stack) < 2)
		return ;
	(*stack)->past = NULL;
	mem = *stack;
	value_c2 = *(mem->content);
	while (mem)
	{
		if (!(mem->next))
			break ;
		value_c1 = *(mem->next->content);
		*(mem->next->content) = value_c2;
		value_c2 = value_c1;
		mem = mem->next;
	}
	*((*stack)->content) = value_c2;
}
