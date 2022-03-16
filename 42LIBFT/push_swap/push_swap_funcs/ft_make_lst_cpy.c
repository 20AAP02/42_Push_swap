/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lst_cpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:05:23 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:33:41 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// Make a copy of a linked list
t_dlst	**ft_make_lst_cpy(t_dlst **stack_a_cpy, t_dlst *stack_a_orig)
{
	int	*value;

	stack_a_cpy = malloc(sizeof(t_dlst *));
	*stack_a_cpy = NULL;
	while (stack_a_orig)
	{
		value = malloc(sizeof(int));
		*value = *(stack_a_orig->content);
		ft_lstadd_back_d_lst(stack_a_cpy, ft_lstnew_d_lst(value));
		stack_a_orig = stack_a_orig->next;
	}
	return (stack_a_cpy);
}
