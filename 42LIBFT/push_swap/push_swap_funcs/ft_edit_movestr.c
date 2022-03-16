/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_movestr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:03:09 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 21:05:32 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

char	*ft_edit_movestr(int times, char *str)
{
	char	*mem;
	int		i;
	int		j;

	if (!times)
		return (str);
	mem = malloc(sizeof(char) * (ft_strlen(str) - times));
	i = 0;
	j = 0;
	while (str[i + 1])
	{
		if ((str[i] == '1' && str[i + 1] == '2') || (str[i] == '2' && str[i + 1] == '1'))
		{
			mem[j] = 'a';
			j++;
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
	free(str);
	return (mem);
}
