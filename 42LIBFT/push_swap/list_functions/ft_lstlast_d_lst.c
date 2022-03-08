#include "../../42_libft/libft.h"
#include "../push_swap.h"

// ft_lstlast_d_lst
d_list *ft_lstlast_d_lst(d_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}