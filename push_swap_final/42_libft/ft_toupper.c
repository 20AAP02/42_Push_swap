/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:24:15 by amaria-m          #+#    #+#             */
/*   Updated: 2021/11/05 11:24:15 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pushswap/push_swap.h"
#include "../ft_printf/ft_printf.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	else
		return (c);
}
