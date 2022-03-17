/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:07:46 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:40:35 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_upd(t_sort *sort_s, char *move, t_dlst **stack_a, t_dlst **stack_b)
{
	char	*mem;

	if (!(sort_s->moves_str))
		sort_s->moves_str = ft_strjoin(move, "");
	else
	{
		mem = ft_strjoin(sort_s->moves_str, move);
		free(sort_s->moves_str);
		sort_s->moves_str = mem;
	}
	while (*move)
	{
		sort_s->n_moves += 1;
		ft_change_lst(*move, stack_a, stack_b);
		move++;
	}
}
