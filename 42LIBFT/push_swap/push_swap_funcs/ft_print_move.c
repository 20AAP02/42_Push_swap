/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:06:07 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:06:08 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_print_move(char a)
{
	if (a == '1')
		ft_printf("sa\n");
	else if (a == '2')
		ft_printf("sb\n");
	else if (a == 'a')
		ft_printf("ss\n");
	else if (a == '3')
		ft_printf("pa\n");
	else if (a == '4')
		ft_printf("pb\n");
	else if (a == '5')
		ft_printf("ra\n");
	else if (a == '6')
		ft_printf("rb\n");
	else if (a == 'b')
		ft_printf("rr\n");
	else if (a == '7')
		ft_printf("rra\n");
	else if (a == '8')
		ft_printf("rrb\n");
	else if (a == 'c')
		ft_printf("rrr\n");
}
