/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_dmoves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:02:43 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:39:18 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

int	ft_count_dmoves(char *str)
{
	int	i;
	int	times;

	times = 0;
	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '1' && str[i + 1] == '2')
		{
			times++;
			i++;
		}
		if (str[i] == '2' && str[i + 1] == '1')
		{
			times++;
			i++;
		}
		i++;
	}
	return (times);
}
