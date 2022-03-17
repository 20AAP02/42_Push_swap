/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:07:13 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:07:14 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

int	ft_str_arr_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
