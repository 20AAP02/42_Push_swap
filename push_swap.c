
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

// ft_atoi but with doubles
double ft_atoi(const char *str)
{
	double number;
	double sign;

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

// ft_split

static int	ft_issep(char s, char c)
{
	return (s == c || s == '\0');
}

static int	countwords(char const *s, char c)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	while (s[index] != '\0')
	{
		if (ft_issep(s[index], c) == 0 && ft_issep(s[index + 1], c) == 1)
			words++;
		index++;
	}
	return (words);
}

static void	ft_cpywords(char *dest, char *src, char c)
{
	int	index;

	index = 0;
	while (ft_issep(src[index], c) == 0)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
}

static void	do_the_split(char **matriz, char *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	*str;

	i = 0;
	word = 0;
	str = s;
	while (s[i] != '\0')
	{
		if (ft_issep(s[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_issep(str[i + j], c) == 0)
				j++;
			matriz[word] = malloc((j + 1) * sizeof(char));
			if (!matriz[word])
				return ;
			ft_cpywords(matriz[word], str + i, c);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**matriz;
	int		words;

	if (!s)
		return (NULL);
	words = countwords(s, c);
	matriz = malloc((words + 1) * sizeof(char *));
	if (!matriz)
		return (NULL);
	matriz[words] = NULL;
	do_the_split(matriz, (char *)s, c);
	return (matriz);
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
		if (*lst)
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
	temp = ft_lstlast_d_lst(*lst);
	if (temp)
		temp->next = new;
	else
		*lst = new;
	new->past = temp;
	new->next = NULL;
}

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



// Operations functions

void ft_sa(d_list *stack)
{
	int value;

	if (ft_lstsize_d_lst(stack) < 2)
		return ;
	value = *(stack->next->content);
	*(stack->next->content) = *(stack->content);
	*(stack->content) = value;
}

void ft_sb(d_list *stack)
{
	int value;

	if (ft_lstsize_d_lst(stack) < 2)
		return ;
	value = *(stack->next->content);
	*(stack->next->content) = *(stack->content);
	*(stack->content) = value;
}

void ft_ss(d_list *stack_a, d_list *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void ft_pa(d_list **stack_a, d_list **stack_b)
{
	d_list *mem;

	if (ft_lstsize_d_lst(*stack_b) < 1)
		return ;
	mem = (*stack_b)->next;
	ft_lstadd_front_d_lst(stack_a, *stack_b);
	*stack_b = mem;
}

void ft_pb(d_list **stack_a, d_list **stack_b)
{
	d_list *mem;

	if (ft_lstsize_d_lst(*stack_a) < 1)
		return ;
	mem = (*stack_a)->next;
	ft_lstadd_front_d_lst(stack_b, *stack_a);
	*stack_a = mem;
}

void ft_ra(d_list **stack)
{
	d_list *mem;
	int value_c2;
	int value_c1;

	if (ft_lstsize_d_lst(*stack) < 2)
		return ;
	(*stack)->past = NULL;
	mem = ft_lstlast_d_lst(*stack);
	value_c2 = *(mem->content);
	while (mem)
	{
		if (!(mem->past))
			break ;
		value_c1 = *(mem->past->content);
		*(mem->past->content) = value_c2;
		value_c2 = value_c1;
		mem = mem->past;
	}
	mem = ft_lstlast_d_lst(*stack);
	*(mem->content) = value_c2;
}

void ft_rb(d_list **stack)
{
	d_list *mem;
	int value_c2;
	int value_c1;

	if (ft_lstsize_d_lst(*stack) < 2)
		return ;
	(*stack)->past = NULL;
	mem = ft_lstlast_d_lst(*stack);
	value_c2 = *(mem->content);
	while (mem)
	{
		if (!(mem->past))
			break ;
		value_c1 = *(mem->past->content);
		*(mem->past->content) = value_c2;
		value_c2 = value_c1;
		mem = mem->past;
	}
	mem = ft_lstlast_d_lst(*stack);
	*(mem->content) = value_c2;
}

void ft_rr(d_list **stack_a, d_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void ft_rra(d_list **stack)
{
	d_list *mem;
	int value_c2;
	int value_c1;

	if (ft_lstsize_d_lst(*stack) < 2)
		return ;
	(*stack)->past = NULL;
	mem = *stack;
	value_c2 = *(mem->content);
	while (mem)
	{
		if (!(mem->next))
			break ;
		value_c1 = *(mem->next->content);
		*(mem->next->content) = value_c2;
		value_c2 = value_c1;
		mem = mem->next;
	}
	*((*stack)->content) = value_c2;
}

void ft_rrb(d_list **stack)
{
	d_list *mem;
	int value_c2;
	int value_c1;

	if (ft_lstsize_d_lst(*stack) < 2)
		return ;
	(*stack)->past = NULL;
	mem = *stack;
	value_c2 = *(mem->content);
	while (mem)
	{
		if (!(mem->next))
			break ;
		value_c1 = *(mem->next->content);
		*(mem->next->content) = value_c2;
		value_c2 = value_c1;
		mem = mem->next;
	}
	*((*stack)->content) = value_c2;
}

void ft_rrr(d_list **stack_a, d_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}

// Checker function (checks if stack_a is sorted)
int ft_list_sorted(d_list *stack)
{
	if (!stack)
		return (2);
	while (stack->next)
	{
		if (*(stack->content) > *(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Function to check if parameters have no errors (too many lines)
int ft_check_parameters(int argc, char **argv)
{
	double *arr;
	int i;
	int j;

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
		arr[i - 1] = ft_atoi(argv[i]);
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

// function to collect the parameters of the stack_a
d_list **ft_collect_integers(int argc, char **argv, int k)
{
	d_list **stack_a;
	int *value;
	int i;

	stack_a = malloc(sizeof(d_list*));
	*stack_a = NULL;
	i = k;
	while ((k == 1 && i < argc) || (k == 0 && i <= argc))
	{
		value = malloc(sizeof(int));
		*value = ft_atoi(argv[i++]);
		ft_lstadd_back_d_lst(stack_a, ft_lstnew_d_lst(value));
	}
	return (stack_a);
}

// function to print linked list (uses printf)
void ft_print_linked_list(d_list *stack_a)
{
	d_list *mem;

	mem = stack_a;
	while (stack_a)
	{
		printf("%i\n", *(stack_a->content));
		stack_a = stack_a->next;
	}
}

// Sort functions
int ft_sort_stack0(d_list **stack_a, d_list **stack_b)
{
	d_list *start_a;
	d_list *start_b;
	int i;

	while (ft_lstsize_d_lst(*stack_a) > 1)
	{
		start_a = *stack_a;
		start_b = *stack_b;
		i = 0;
		while (i < ft_lstsize_d_lst(*stack_a))
		{
			if (*(start_a->content) < *(start_a->next->content))
			{
				ft_sa(start_a);
				printf("sa\n");
			}
			ft_ra(stack_a);
			printf("ra\n");
			i++;
		}
		ft_pb(stack_a, stack_b);
		printf("pb\n");
	}
	while (ft_lstsize_d_lst(*stack_b))
	{
		ft_pa(stack_a, stack_b);
		printf("pa\n");
	}
	return (1);
}

int ft_sort_stack1(d_list **stack_a, d_list **stack_b)
{
	return (1);
}

// free split argv[1] strings
void ft_free_split(char **mem)
{
	int i;

	i = -1;
	while (mem[++i])
		free(mem[i]);
	free(mem);
}

//gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg
int main (int argc, char **argv)
{
	d_list **stack_a;
	d_list **stack_b;
	char **mem;
	int check_param;

	// Checking for parameters errors (1 - there are non integers) (2 - bigger than integer) (3 - to many arguments) (4 - there are duplicates)
	if (ft_check_parameters(argc, argv) && ft_check_parameters(argc, argv) != 5)
	{
		printf("error %i\n", ft_check_parameters(argc, argv));
		return (1);
	}
	if (ft_check_parameters(argc, argv) == 5)
		mem = ft_split(argv[1], ' ');
	if (ft_check_parameters(argc, argv) == 5)
		stack_a = ft_collect_integers(argc, mem, 0);
	else
		stack_a = ft_collect_integers(argc, argv, 1);

	// Creating stack_b
	stack_b = malloc(sizeof(d_list*));
	*stack_b = NULL;
	
	///*
	// testing function to print double linked list at start
	printf("-------------\nStack A Start\n");
	ft_print_linked_list(*stack_a);
	printf("-------------\nStack B Start\n");
	ft_print_linked_list(*stack_b);

	// check if stack_a is sorted at start
	printf("-------------\nStack_A sorted: ");
	printf("%i\n", ft_list_sorted(*stack_a));


	// Sorting
	printf("\n-------------------------\n\n");
	//*/
	ft_sort_stack0(stack_a, stack_b);

	///*
	// testing function to print double linked list at end
	printf("-------------\nStack A End\n");
	ft_print_linked_list(*stack_a);
	printf("-------------\nStack B End\n");
	ft_print_linked_list(*stack_b);

	// check if stack_a is sorted at end
	printf("-------------\nStack_A sorted: ");
	printf("%i\n", ft_list_sorted(*stack_a));
	//*/
	// free lists
	if (ft_check_parameters(argc, argv) == 5)
		ft_free_split(mem);
	ft_lstclear_d_lst(stack_a);
	ft_lstclear_d_lst(stack_b);

	return (0);
}