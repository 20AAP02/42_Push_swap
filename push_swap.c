
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

// double linked list struct
typedef struct d_list
{
	struct d_list	*past;
	int					*content;
	struct d_list	*next;
}	d_list;

// sorting scores struct (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)
typedef struct s_sort
{
	int		n_moves;
	char	*moves_str;
}	s_sort;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	new_str = malloc(i + j + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = 0;
	return (new_str);
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
	while ((k == 1 && i < argc) || (k == 0 && argv[i]))
	{
		value = malloc(sizeof(int));
		*value = ft_atoi(argv[i++]);
		ft_lstadd_back_d_lst(stack_a, ft_lstnew_d_lst(value));
	}
	return (stack_a);
}

// Make a copy of a linked list
d_list **ft_make_lst_cpy(d_list **stack_a_cpy, d_list *stack_a_orig)
{
	int *value;

	// Creating stack_a & stack_b copies
	stack_a_cpy = malloc(sizeof(d_list*));
	*stack_a_cpy = NULL;

	while (stack_a_orig)
	{
		value = malloc(sizeof(int));
		*value = *(stack_a_orig->content);
		ft_lstadd_back_d_lst(stack_a_cpy, ft_lstnew_d_lst(value));
		stack_a_orig = stack_a_orig->next;
	}

	return (stack_a_cpy);
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

// function to apply move to stacks (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)
void ft_change_lst(char move, d_list **stack_a, d_list **stack_b)
{
	if (move == '1')
		ft_sa(*stack_a);
	else if (move == '2')
		ft_sb(*stack_b);
	else if (move == '3')
		ft_pa(stack_a, stack_b);
	else if (move == '4')
		ft_pb(stack_a, stack_b);
	else if (move == '5')
		ft_ra(stack_a);
	else if (move == '6')
		ft_rb(stack_b);
	else if (move == '7')
		ft_rra(stack_a);
	else if (move == '8')
		ft_rrb(stack_b);
}

// function to update sort score
void ft_update_sort_score(s_sort *sort_s, char *move, d_list **stack_a, d_list **stack_b)
{
	char *mem;

	if (!(sort_s->moves_str))
		sort_s->moves_str = ft_strjoin(move, "");
	else
	{
		mem = ft_strjoin(sort_s->moves_str, move);
		free(sort_s->moves_str);
		sort_s->moves_str = mem;
	}
	while (*move)
	{
		sort_s->n_moves += 1;
		ft_change_lst(*move++, stack_a, stack_b);
	}
}

// Sort functions
void ft_sort_stack0(d_list **stack_a, d_list **stack_b, s_sort *sort_0)
{
	int i;

	while (ft_lstsize_d_lst(*stack_a) > 1)
	{
		i = 0;
		while (i < ft_lstsize_d_lst(*stack_a))
		{
			if (*((*stack_a)->content) < *((*stack_a)->next->content) && !ft_list_sorted(*stack_a))
				ft_update_sort_score(sort_0, "1", stack_a, stack_b);
			if (ft_list_sorted(*stack_a))
				break ;
			ft_update_sort_score(sort_0, "5", stack_a, stack_b);
			i++;
		}
		if (ft_list_sorted(*stack_a))
			break ;
		ft_update_sort_score(sort_0, "4", stack_a, stack_b);
	}
	while (ft_lstsize_d_lst(*stack_b))
		ft_update_sort_score(sort_0, "3", stack_a, stack_b);
}

// sort algrithm for lists of 3 numbers
void ft_sort_stack1(d_list **stack_a, s_sort *sort_1)
{
	int mem1;
	int mem2;
	int mem3;

	if (ft_lstsize_d_lst(*stack_a) != 3)
		return ;
	mem1 = *((*stack_a)->content);
	mem2 = *((*stack_a)->next->content);
	mem3 = *((*stack_a)->next->next->content);

	if (mem1 > mem2 && mem1 < mem3)
		ft_update_sort_score(sort_1, "1", stack_a, stack_a);
	else if (mem1 > mem2 && mem1 > mem3 && mem2 > mem3)
		ft_update_sort_score(sort_1, "17", stack_a, stack_a);
	else if (mem1 > mem2 && mem1 > mem3 && mem2 < mem3)
		ft_update_sort_score(sort_1, "5", stack_a, stack_a);
	else if (mem1 < mem2 && mem1 < mem3 && mem2 > mem3)
		ft_update_sort_score(sort_1, "15", stack_a, stack_a);
	else if (mem1 < mem2 && mem1 > mem3)
		ft_update_sort_score(sort_1, "7", stack_a, stack_a);
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
	d_list **stack_a_cpy;
	d_list **stack_b_cpy;
	s_sort sort_1;

	d_list **stack_a;
	d_list **stack_b;
	s_sort sort_0;
	char **mem;

	// Checking for parameters errors (1 - there are non integers) (2 - bigger than integer) (3 - to many arguments) (4 - there are duplicates)
	if (ft_check_parameters(argc, argv) && ft_check_parameters(argc, argv) != 5)
		return (printf("error %i\n", ft_check_parameters(argc, argv)));
	if (ft_check_parameters(argc, argv) == 5)
		mem = ft_split(argv[1], ' ');
	if (ft_check_parameters(argc, argv) == 5)
		stack_a = ft_collect_integers(argc, mem, 0);
	else
		stack_a = ft_collect_integers(argc, argv, 1);

	// Creating stack_b
	stack_b = malloc(sizeof(d_list*));
	*stack_b = NULL;

	// initialising sort_0 scores
	sort_0.n_moves = 0;
	sort_0.moves_str = NULL;

	// initialising sort_1 scores
	sort_1.n_moves = 0;
	sort_1.moves_str = NULL;

	// making stack_a copy
	stack_a_cpy = ft_make_lst_cpy(stack_a_cpy, *stack_a);
	
	// Sorting lists
	ft_sort_stack0(stack_a, stack_b, &sort_0);
	ft_sort_stack1(stack_a_cpy, &sort_1);

	printf("%s -- %i\n", sort_0.moves_str, sort_0.n_moves);
	printf("%s -- %i\n", sort_1.moves_str, sort_1.n_moves);

	// free lists
	free(sort_0.moves_str);
	if (ft_check_parameters(argc, argv) == 5)
		ft_free_split(mem);
	ft_lstclear_d_lst(stack_a);
	ft_lstclear_d_lst(stack_b);

	ft_lstclear_d_lst(stack_a_cpy);
	free(sort_1.moves_str);
	
	return (0);
}