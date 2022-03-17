/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:01:17 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/17 11:10:40 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

int	ft_fr(void *ptr)
{
	free(ptr);
	return (0);
}

int	ft_block_check(int argc, char **argv, int j, int i)
{
	double	*arr;

	arr = malloc(sizeof(double) * (argc - 1));
	i = 0;
	while (++i < argc)
	{
		arr[i - 1] = ft_atoi_dbl(argv[i]);
		if (arr[i - 1] > 2147483647 || arr[i - 1] < -2147483648)
			return (ft_fr(arr) + 2);
	}
	i = -1;
	while (++i < (argc - 1))
	{
		j = -1;
		while (++j < (argc - 1))
			if (arr[i] == arr[j] && i != j)
				return (ft_fr(arr) + 4);
	}
	return (ft_fr(arr));
}

int	ft_check_parameters(int argc, char **argv, int k)
{
	int		i;
	int		j;

	if (k)
		argc = ft_str_arr_size(argv);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
				if (argv[i][j] != ' ')
					return (1);
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == ' ')
				return (5);
			if (j > 9)
				return (2);
		}
	}
	if (ft_block_check(argc, argv, j, i))
		return (ft_block_check(argc, argv, j, i));
	return (0);
}
