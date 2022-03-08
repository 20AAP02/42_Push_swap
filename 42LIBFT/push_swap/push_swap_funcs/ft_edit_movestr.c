#include "../../42_libft/libft.h"
#include "../push_swap.h"

// (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)
char *ft_edit_movestr(int times, char *str)
{
	char *mem;
	int i;
	int j;

	if (!times)
		return (str);
	mem = malloc(sizeof(char) * (ft_strlen(str) - times));
	i = 0;
	j = 0;
	while (str[i+1])
	{
		if ((str[i] == '1' && str[i+1] == '2') || (str[i] == '2' && str[i+1] == '1'))
		{
			mem[j] = 'a';
			j++;
			i++;
		}
		else if ((str[i] == '5' && str[i+1] == '6') || (str[i] == '6' && str[i+1] == '5'))
		{
			mem[j] = 'b';
			i++;
			j++;
		}
		else if ((str[i] == '7' && str[i+1] == '8') || (str[i] == '8' && str[i+1] == '7'))
		{
			mem[j] = 'c';
			i++;
			j++;
		}
		else
		{
			mem[j] = str[i];
			j++;
		}
		i++;
		if(!str[i])
			break ;
	}
	if (str[i])
		mem[j] = str[i];
	mem[j] = '\0';
	free(str);
	return (mem);
}
