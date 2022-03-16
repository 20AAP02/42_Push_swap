/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:41:21 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 16:41:22 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_rb(t_dlst **stack)
{
	t_dlst	*mem;
	int		value_c2;
	int		value_c1;

	if (ft_lstsize_d_lst(*stack) < 2)
		return ;
	(*stack)->past = NULL;
	mem = ft_lstlast_d_lst(*stack);
	value_c2 = *(mem->content);
	while (mem)
	{
		if (!(mem->past))
			break ;
		value_c1 = *(mem->past->content);
		*(mem->past->content) = value_c2;
		value_c2 = value_c1;
		mem = mem->past;
	}
	mem = ft_lstlast_d_lst(*stack);
	*(mem->content) = value_c2;
}
