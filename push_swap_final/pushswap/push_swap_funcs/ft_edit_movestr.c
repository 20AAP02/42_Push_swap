/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_movestr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:03:09 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/17 16:44:12 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

void	ft_blo(char *str, int i, int j, char *mem)
{
	while (str[i + 1])
	{
		if (str[i] == '1' && str[i + 1] == '2')
		{
			mem[j++] = 'a';
			i++;
		}
		else if (str[i] == '2' && str[i + 1] == '1')
		{
			mem[j++] = 'a';
			i++;
		}
		else
		{
			mem[j] = str[i];
			j++;
		}
		i++;
		if (!str[i])
			break ;
	}
	if (str[i])
		mem[j] = str[i];
	mem[j] = '\0';
}

char	*ft_edit_movestr(int times, char *str)
{
	char	*mem;

	if (!times)
		return (str);
	mem = malloc(sizeof(char) * (ft_strlen(str) - times));
	ft_blo(str, 0, 0, mem);
	free(str);
	return (mem);
}
