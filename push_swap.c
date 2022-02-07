#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

typedef struct d_list
{
	struct d_list	*past;
	int					*content;
	struct d_list	*next;
}	d_list;

// LIBFT FUNCTIONS

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int ft_atoi(const char *str)
{
	int number;
	int sign;

	sign = 1;
	number = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	return (number * sign);
}

// PUSH_SWAP FUNCTIONS

// List funcions

// ft_lstnew_d_lst
d_list *ft_lstnew_d_lst(void *content)
{
	d_list *new;

	new = malloc(sizeof(d_list));
	if (!new)
		return (NULL);
	new->past = NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}

// ft_lstadd_front_d_lst
void ft_lstadd_front_d_lst(d_list **lst, d_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		(*lst)->past = new;
		*lst = new;
	}
}

// ft_lstsize_d_lst
int ft_lstsize_d_lst(d_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// ft_lstlast_d_lst
d_list *ft_lstlast_d_lst(d_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// ft_lstadd_back_d_lst
void ft_lstadd_back_d_lst(d_list **lst, d_list *new)
{
	d_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast_d_lst(*lst);
	temp->next = new;
	new->past = temp;
}

// ft_lstdelone_d_lst
void ft_lstdelone_d_lst(d_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// ft_lstclear_d_lst
void ft_lstclear_d_lst(d_list **lst, void (*del)(void*))
{
	d_list *ptr;

	if (lst)
	{
		while (*lst)
		{
			ptr = (*lst)-> next;
			del((*lst)-> content);
			free(*lst);
			*lst = ptr;
		}
	}
}



// Operations functions

void ft_sa(int *stack)
{
	int copy;

	copy = stack[0];
	stack[0] = stack[1];
	stack[1] = copy;
}

void ft_sb(int *stack)
{
	int copy;

	copy = stack[0];
	stack[0] = stack[1];
	stack[1] = copy;
}

void ft_ss(int *stack_a, int *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void ft_pa(int *stack_a, int *stack_b, int size_a, int size_b)
{
	stack_a[0] = stack_b[0];
}

void ft_pb(int *stack_a, int *stack_b)
{
	stack_b[0] = stack_a[0];
}

void ft_ra(int *stack, int size)
{
	int i;
	int copy_1;
	int copy_2;

	i = size - 1;
	copy_2 = stack[i];
	while (i)
	{
		copy_1 = stack[i - 1];
		stack[i - 1] = copy_2;
		copy_2 = copy_1;
		i--;
	}
	stack[size - 1] = copy_2;
}

void ft_rb(int *stack, int size)
{
	int i;
	int copy_1;
	int copy_2;

	i = size - 1;
	copy_2 = stack[i];
	while (i)
	{
		copy_1 = stack[i - 1];
		stack[i - 1] = copy_2;
		copy_2 = copy_1;
		i--;
	}
	stack[size - 1] = copy_2;
}

void ft_rr(int *stack_a, int *stack_b, int size)
{
	ft_ra(stack_a, size);
	ft_rb(stack_b, size);
}

// Checker function (checks if stack_a is sorted)
// TODO

// Function to check if parameters have no errors
// TODO

// General functions

// function to collect the parameters of the stack_a
d_list *ft_collect_integers(int argc, char **argv)
{
	// TODO
}

int main (int argc, char **argv)
{
	d_list *head;

	// Checking for parameters errors
	// TODO

	// Passing stack_a parameters to array
	head = ft_collect_integers (argc, argv);

	return (0);
}