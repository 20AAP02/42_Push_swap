/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max_pos_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:03:48 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:03:49 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

int	ft_find_max_pos_lst(t_dlst *stack)
{
	int	i;
	int	j;
	int	max_value;

	i = 0;
	j = 0;
	max_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) > max_value)
		{
			max_value = *(stack->content);
			j = i;
		}
		i++;
		stack = stack->next;
	}
	return (j);
}
