#include "../../42_libft/libft.h"
#include "../push_swap.h"

// ft_lstadd_back_d_lst
void ft_lstadd_back_d_lst(d_list **lst, d_list *new)
{
	d_list	*temp;

	if (!lst || !new)
		return ;
	temp = ft_lstlast_d_lst(*lst);
	if (temp)
		temp->next = new;
	else
		*lst = new;
	new->past = temp;
	new->next = NULL;
}