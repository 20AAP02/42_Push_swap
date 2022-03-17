/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_d_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:37:08 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 16:37:31 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// ft_lstadd_back_d_lst
void	ft_lstadd_back_d_lst(t_dlst **lst, t_dlst *new)
{
	t_dlst	*temp;

	if (!lst || !new)
		return ;
	temp = ft_lstlast_d_lst(*lst);
	if (temp)
		temp->next = new;
	else
		*lst = new;
	new->past = temp;
	new->next = NULL;
}
