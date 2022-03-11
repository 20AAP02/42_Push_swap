#include "../../42_libft/libft.h"
#include "../push_swap.h"
#include "../../ft_printf/ft_printf.h"

// ft_lstclear_d_lst
void ft_lstclear_d_lst(d_list **lst)
{
	d_list *ptr;

	if (lst)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = ptr;
		}
	}
	free(lst);
}