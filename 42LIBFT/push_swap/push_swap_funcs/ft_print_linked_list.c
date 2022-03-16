/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:05:55 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:05:56 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// function to print linked list (uses printf)
void	ft_print_linked_list(t_dlst *stack_a)
{
	while (stack_a)
	{
		ft_printf("%i\n", *(stack_a->content));
		stack_a = stack_a->next;
	}
}
