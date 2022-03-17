/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_d_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:37:57 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 16:38:58 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// ft_lstnew_d_lst
t_dlst	*ft_lstnew_d_lst(void *content)
{
	t_dlst	*new;

	new = malloc(sizeof(t_dlst));
	if (!new)
		return (NULL);
	new->past = NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}
