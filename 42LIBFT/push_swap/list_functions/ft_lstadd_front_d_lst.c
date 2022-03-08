#include "../../42_libft/libft.h"
#include "../push_swap.h"

// ft_lstadd_front_d_lst
void ft_lstadd_front_d_lst(d_list **lst, d_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		if (*lst)
			(*lst)->past = new;
		*lst = new;
	}
}