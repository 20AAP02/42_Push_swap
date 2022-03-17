/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:04:26 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:04:34 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

int	ft_mp_lst(t_dlst *stack)
{
	int	i;
	int	j;
	int	min_value;

	i = 0;
	j = 0;
	min_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) < min_value)
		{
			min_value = *(stack->content);
			j = i;
		}
		i++;
		stack = stack->next;
	}
	return (j);
}
