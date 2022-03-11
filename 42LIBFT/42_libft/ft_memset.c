/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:13:11 by amaria-m          #+#    #+#             */
/*   Updated: 2021/11/05 11:13:11 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap/push_swap.h"
#include "../ft_printf/ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;
	char	*ptr;

	ptr = b;
	index = 0;
	while (index < len)
	{
		ptr[index] = c;
		index++;
	}
	return (ptr);
}
