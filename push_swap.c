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
	if (!*lst)
	{
		new->next = new;
		new->past = new;
		*lst = new;
	}
	else if (lst && new)
	{
		new->next = *lst;
		new->past = (*lst)->past;
		(*lst)->past->next = new;
		(*lst)->past = new;
		*lst = new;
	}
}

// ft_lstsize_d_lst
int ft_lstsize_d_lst(d_list *lst)
{
	d_list *mem;
	int	i;

	mem = lst;
	i = 0;
	if (!lst)
		return (0);
	while (lst && lst->next != mem)
	{
		lst = lst->next;
		i++;
	}
	return (i + 1);
}

// ft_lstlast_d_lst
d_list *ft_lstlast_d_lst(d_list *lst)
{
	d_list *mem;

	mem = lst;
	if (!lst)
		return (NULL);
	while (lst->next && lst->next != mem)
		lst = lst->next;
	return (lst);
}

// ft_lstadd_back_d_lst
void ft_lstadd_back_d_lst(d_list **lst, d_list *new)
{
	d_list	*temp;
	d_list	*mem;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast_d_lst(*lst);
	mem = temp->next;
	temp->next = new;
	new->past = temp;
	new->next = mem;
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
	d_list *last;

	last = ft_lstlast_d_lst(*lst);
	last->next = NULL;
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

void ft_sa(d_list *stack)
{
	int mem;

	mem = *(stack->content);
	*(stack->content) = *(stack->next->content);
	*(stack->next->content) = mem;
}

void ft_sb(d_list *stack)
{
	int mem;

	mem = *(stack->content);
	*(stack->content) = *(stack->next->content);
	*(stack->next->content) = mem;
}

void ft_ss(d_list *stack_a, d_list *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void ft_pa(d_list **stack_a, d_list **stack_b)
{
	d_list *mem;

	if (!*stack_b)
		return ;
	if (ft_lstsize_d_lst(*stack_b) > 1)
	{
		(*stack_b)->next->past = (*stack_b)->past;
		(*stack_b)->past->next = (*stack_b)->next;
		ft_lstadd_front_d_lst(stack_a, *stack_b);
	}
	else
	{
		ft_lstadd_front_d_lst(stack_a, *stack_b);
		*stack_b = NULL;
	}
}
/*
void ft_pb(int *stack_a, int *stack_b);

void ft_ra(int *stack, int size);

void ft_rb(int *stack, int size);

void ft_rr(int *stack_a, int *stack_b, int size);
*/
// Checker function (checks if stack_a is sorted)
// TODO

// Function to check if parameters have no errors
// TODO

// General functions

// function to collect the parameters of the stack_a
d_list **ft_collect_integers(int argc, char **argv)
{
	d_list **stack_a;
	int *value;
	int i;

	value = malloc(sizeof(int));
	*value = ft_atoi(argv[1]);
	stack_a = malloc(sizeof(d_list*));
	*stack_a = NULL;
	ft_lstadd_back_d_lst(stack_a, ft_lstnew_d_lst(value));
	i = 2;
	while (i < argc)
	{
		value = malloc(sizeof(int));
		*value = ft_atoi(argv[i]);
		ft_lstadd_back_d_lst(stack_a, ft_lstnew_d_lst(value));
		i++;
	}
	return (stack_a);
}

// function to print linked list (uses printf)
void ft_print_linked_list(d_list *stack_a)
{
	d_list *mem;

	mem = stack_a;
	while (stack_a->next != mem && stack_a)
	{
		printf("%i\n", *(stack_a->content));
		stack_a = stack_a->next;
	}
	printf("%i\n", *(stack_a->content));
}

int main (int argc, char **argv)
{
	d_list **stack_a;
	d_list **stack_b;
	int test = 15;

	stack_b = malloc(sizeof(d_list*));
	*stack_b = ft_lstnew_d_lst(&test);

	// Checking for parameters errors
	// TODO

	// Passing stack_a parameters to double linked list
	stack_a = ft_collect_integers(argc, argv);
	ft_lstlast_d_lst(*stack_a)->next = *stack_a;

	// testing function to print double linked list
	ft_print_linked_list(*stack_b);
	printf("-------------\n");
	ft_print_linked_list(*stack_a);
	printf("-------------\n");
	ft_pa(stack_a, stack_b);
	ft_print_linked_list(*stack_b);
	printf("-------------\n");
	ft_print_linked_list(*stack_a);
	printf("-------------\n");
	printf("%i\n", ft_lstsize_d_lst(*stack_a));
	ft_lstclear_d_lst(stack_a, free);
	free(stack_a);

	return (0);
}