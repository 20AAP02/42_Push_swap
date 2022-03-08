#include "../../42_libft/libft.h"
#include "../push_swap.h"

// Function to check if parameters have no errors (too many lines)
int ft_check_parameters(int argc, char **argv, int k)
{
	double *arr;
	int i;
	int j;

	if (k)
		argc = ft_str_arr_size(argv);
	if (argc > 501)
		return (3);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while(argv[i][++j])
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != ' ')
				return (1);
		j = -1;
		while(argv[i][++j])
		{
			if (argv[i][j] == ' ')
				return (5);
			if (j > 9)
				return (2);
		}
	}
	arr = malloc(sizeof(double) * (argc - 1));
	i = 0;
	while (++i < argc)
	{
		arr[i - 1] = ft_atoi_dbl(argv[i]);
		if (arr[i - 1] > 2147483647 || arr[i - 1] < -2147483648)
			return (2);
	}
	i = -1;
	while (++i < (argc - 1))
	{
		j = -1;
		while (++j < (argc - 1))
			if (arr[i] == arr[j] && i != j)
				return (4);
	}
	free(arr);
	return (0);
}