#include "../../42_libft/libft.h"
#include "../push_swap.h"

int ft_count_dmoves(char *str)
{
	int i;
	int times;

	times = 0;
	i = 0;
	while (str[i+1])
	{
		if ((str[i] == '1' && str[i+1] == '2') || (str[i] == '2' && str[i+1] == '1'))
		{
			times++;
			i++;
		}
		else if ((str[i] == '5' && str[i+1] == '6') || (str[i] == '6' && str[i+1] == '5'))
		{
			times++;
			i++;
		}
		else if ((str[i] == '7' && str[i+1] == '8') || (str[i] == '8' && str[i+1] == '7'))
		{
			times++;
			i++;
		}
		i++;
	}
	return (times);
}
