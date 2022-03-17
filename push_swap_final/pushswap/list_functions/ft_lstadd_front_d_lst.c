/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_d_lst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:37:34 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 16:38:27 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// ft_lstadd_front_d_lst
void	ft_lstadd_front_d_lst(t_dlst **lst, t_dlst *new)
{
	if (lst && new)
	{
		new->next = *lst;
		if (*lst)
			(*lst)->past = new;
		*lst = new;
	}
}
