/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_k.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:07:30 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:07:30 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_k(t_sort *k, t_dlst **sta, void (*f)(t_dlst**, t_dlst**, t_sort*))
{
	t_dlst	**stack_a_cpy;
	t_dlst	**stack_b_cpy;

	stack_b_cpy = malloc(sizeof(t_dlst *));
	*stack_b_cpy = NULL;
	stack_a_cpy = NULL;
	stack_a_cpy = ft_make_lst_cpy(stack_a_cpy, *sta);
	(*f)(stack_a_cpy, stack_b_cpy, k);
	ft_lstclear_d_lst(stack_a_cpy);
	free(stack_b_cpy);
}
