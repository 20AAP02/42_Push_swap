/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:04:57 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 20:04:58 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// free split argv[1] strings
int	ft_free_split(char **mem)
{
	int	i;

	i = -1;
	while (mem[++i])
		free(mem[i]);
	free(mem);
	return (0);
}
