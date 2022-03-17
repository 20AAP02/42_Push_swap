/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:10:15 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/17 18:07:43 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pushswap/push_swap.h"
#include "../ft_printf/ft_printf.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (lst)
	{
		ptr = lst;
		while (ptr)
		{
			f(ptr -> content);
			ptr = ptr -> next;
		}
	}
}
