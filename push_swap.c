#include <push_swap.h>

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

// PUSH_SWAP FUNCTIONs

// Checker function (checks if stack_a is sorted)
int ft_list_sorted(d_list *stack, int j)
{
	int i;

	i = 0;
	if (!stack)
		return (2);
	if (j)
		while (*(stack->content) != 0)
			stack = stack->next;
	while (stack->next)
	{
		if (*(stack->content) != (*(stack->next->content) - 1))
		{
			if (j)
				printf("-- ( %i, %i ) --\n", *(stack->content), *(stack->next->content));
			return (0);
		}
		stack = stack->next;
		i++;
	}
	return (1);
}

// function to count number of strings in and array of strings
int ft_str_arr_size(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

// Function to check if parameters have no errors (too many lines)
int ft_check_parameters(int argc, char **argv, int k)
{
	double *arr;
	int i;
	int j;

	if (k)
		argc = ft_str_arr_size(argv);
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
void ft_sort_stack0(d_list **stack_a, d_list **stack_b, s_sort *sort_0)
{
	int i;

	while (ft_lstsize_d_lst(*stack_a) > 1)
	{
		i = 0;
		while (i < ft_lstsize_d_lst(*stack_a))
		{
			if (*((*stack_a)->content) < *((*stack_a)->next->content) && !ft_list_sorted(*stack_a, 0))
				ft_update_sort_score(sort_0, "1", stack_a, stack_b);
			if (ft_list_sorted(*stack_a, 0))
				break ;
			ft_update_sort_score(sort_0, "5", stack_a, stack_b);
			i++;
		}
		if (ft_list_sorted(*stack_a, 0))
			break ;
		ft_update_sort_score(sort_0, "4", stack_a, stack_b);
	}
	while (ft_lstsize_d_lst(*stack_b))
		ft_update_sort_score(sort_0, "3", stack_a, stack_b);
}

// function to find position of the minimum number of the stack
int ft_find_min_pos_lst(d_list *stack)
{
	int i;
	int j;
	int min_value;

	i = 0;
	j = 0;
	min_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) < min_value)
		{
			min_value = *(stack->content);
			j = i;
		}
		i++;
		stack = stack->next;
	}
	return (j);
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
		ft_change_lst(*move, stack_a, stack_b);
		move++;
	}
}


// OFICIAL SORT ALGORITHMS --------------

void ft_small_half_to_b(d_list **stack_a, d_list **stack_b, s_sort *sort_p, int value)
{
	int check;

	check = 0;
	if (ft_lstsize_d_lst(*stack_a) % 2)
		check = 1;
	while (ft_lstsize_d_lst(*stack_a) > value)
	{
		if (check)
		{
			if (*((*stack_a)->content) <= value)
				ft_update_sort_score(sort_p, "4", stack_a, stack_b);
			else
				ft_update_sort_score(sort_p, "5", stack_a, stack_b);
		}
		else
		{
			if (*((*stack_a)->content) < value)
				ft_update_sort_score(sort_p, "4", stack_a, stack_b);
			else
				ft_update_sort_score(sort_p, "5", stack_a, stack_b);
		}
		
	}
}

void ft_small_quarter_to_b(d_list **stack_a, d_list **stack_b, s_sort *sort_p, int value)
{
	int check;

	check = 0;
	if (ft_lstsize_d_lst(*stack_a) % 2)
		check = 1;
	
	if (check)
		while (*((*stack_a)->content) <= value)
			ft_update_sort_score(sort_p, "4", stack_a, stack_b);
	else
		while (*((*stack_a)->content) < value)
			ft_update_sort_score(sort_p, "4", stack_a, stack_b);
}

void ft_big_quarter_to_a(d_list **stack_a, d_list **stack_b, s_sort *sort_p, int value)
{
	int check;

	check = 1;
	if (ft_lstsize_d_lst(*stack_a) % 2)
		check = 0;
	if (check)
	{
		while (ft_lstsize_d_lst(*stack_b) > value)
		{
			if (*((*stack_b)->content) >= (value * 3))
				ft_update_sort_score(sort_p, "3", stack_a, stack_b);
			else
				ft_update_sort_score(sort_p, "6", stack_a, stack_b);
		}
	}
	else
	{
		while (ft_lstsize_d_lst(*stack_b) > value)
		{
			if (*((*stack_b)->content) > (value * 3))
				ft_update_sort_score(sort_p, "3", stack_a, stack_b);
			else
				ft_update_sort_score(sort_p, "6", stack_a, stack_b);
		}
	}
}

// --------------------------------------

int ft_find_max_pos_lst(d_list *stack)
{
	int i;
	int j;
	int max_value;

	i = 0;
	j = 0;
	max_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) > max_value)
		{
			max_value = *(stack->content);
			j = i;
		}
		i++;
		stack = stack->next;
	}
	return (j);
}


int ft_find_max_lst(d_list *stack)
{
	int max_value;

	max_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) > max_value)
			max_value = *(stack->content);
		stack = stack->next;
	}
	return (max_value);
}

int ft_find_min_lst(d_list *stack)
{
	int min_value;

	min_value = *(stack->content);
	while (stack)
	{
		if (*(stack->content) < min_value)
			min_value = *(stack->content);
		stack = stack->next;
	}
	return (min_value);
}

int ft_average_lst(d_list *stack)
{
	int sum;
	int i;

	sum = 0;
	i = 0;
	while (stack)
	{
		sum += *(stack->content);
		stack = stack->next;
		i++;
	}
	return (sum / i);
}

void ft_sort_stack4(d_list **stack_a, d_list **stack_b, s_sort *sort_4)
{
	int average;
	int size;
	int i;
	int pos;

	average = ft_average_lst(*stack_a);
	size = ft_lstsize_d_lst(*stack_a);
	i = 0;
	while (i < size)
	{
		if (*((*stack_a)->content) > average)
			ft_update_sort_score(sort_4, "4", stack_a, stack_b);
		else
			ft_update_sort_score(sort_4, "5", stack_a, stack_b);
		i++;
	}
	i = 0;
	while (ft_lstsize_d_lst(*stack_b))
	{
		pos = ft_find_min_pos_lst(*stack_b);
		if (pos <= (ft_lstsize_d_lst(*stack_b) / 2))
			while (ft_find_min_pos_lst(*stack_b) != 0)
				ft_update_sort_score(sort_4, "6", stack_a, stack_b);
		else
			while (ft_find_min_pos_lst(*stack_b) != 0)
				ft_update_sort_score(sort_4, "8", stack_a, stack_b);
		ft_update_sort_score(sort_4, "3", stack_a, stack_b);
		ft_update_sort_score(sort_4, "5", stack_a, stack_b);
		i++;
	}
	while (*((*stack_a)->content) <= average)
		ft_update_sort_score(sort_4, "4", stack_a, stack_b);
	while (ft_lstsize_d_lst(*stack_b))
	{
		pos = ft_find_max_pos_lst(*stack_b);
		if (pos <= (ft_lstsize_d_lst(*stack_b) / 2))
			while (ft_find_max_pos_lst(*stack_b) != 0)
				ft_update_sort_score(sort_4, "6", stack_a, stack_b);
		else
			while (ft_find_max_pos_lst(*stack_b) != 0)
				ft_update_sort_score(sort_4, "8", stack_a, stack_b);
		ft_update_sort_score(sort_4, "3", stack_a, stack_b);
	}
}

// (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)


// function to see if it exits a number smaller then i
int ft_lower_then(d_list *stack, int i)
{
	while (stack)
	{
		if (*(stack->content) < i)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// function to see if it exits a number bigger then i
int ft_bigger_then(d_list *stack, int i)
{
	while (stack)
	{
		if (*(stack->content) > i)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// function to see if it exits a number equal to i
int ft_equal_to(d_list *stack, int i)
{
	while (stack)
	{
		if (*(stack->content) == i)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int ft_arr_size(int *arr)
{
	int i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int *ft_resize_arr(int *arr, int num, int action, int *size)
{
	int *mem;
	int i;

	i = 0;
	if (!action && *size == 0)
		return (arr);
	else if (action && (*size == 0))
	{
		arr = malloc(sizeof(int));
		*arr = num;
		*size += 1;
		return (arr);
	}
	else if (action)
	{
		mem = malloc(sizeof(int) * (*size + 1));
		while (i < *size)
		{
			mem[i] = arr[i];
			i++;
		}
		mem[i] = num;
		free(arr);
		arr = mem;
		*size += 1;
		return (arr);
	}
	else
	{
		*size -= 1;
		mem = malloc(sizeof(int) * (*size));
		while (i < *size)
		{
			mem[i] = arr[i];
			i++;
		}
		free(arr);
		arr = mem;
		return (arr);
	}
}

int ft_arr_last(int *arr, int *size)
{
	return (arr[(*size) - 1]);
}

int ft_avg_until_min(d_list *stack, int min)
{
	int sum;
	int i;

	sum = 0;
	i = 0;
	while (stack)
	{
		if (*(stack->content) == min)
			break ;
		sum += *(stack->content);
		stack = stack->next;
		i++;
	}
	return (sum / i);
}

void ft_print_avgs(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		printf("-- |%i| --\n", arr[i++]);
}

// function to calculate best route to sort numbers in stack b
int *ft_calc_route(d_list **stack_a, d_list **stack_b)
{
	d_list *mem;
	int count;
	int *pos;
	int p;

	pos = malloc(sizeof(int) * 2);
	pos[1] = 0;
	pos[0] = 0;
	mem = (*stack_b)->next;
	p = 0;
	count = 0;
	while (mem)
	{
		if (count > pos[1])
			pos[0] = p - count;
		if (count > pos[1])
			pos[1] = count;
		if (*(mem->past->content) < *(mem->content))
			count = 0;
		else
			count++;
		mem = mem->next;
		p++;
	}
	return (pos);
}

// simplify list of ints to [0, N]
void ft_make_range(d_list **stack_a, d_list **stack_b)
{
	d_list **stack_a_cpy;
	d_list *mem;
	int n;
	int i;

	stack_a_cpy = ft_make_lst_cpy(stack_a_cpy, *stack_a);
	while (ft_lstsize_d_lst(*stack_a))
	{
		n = *((*stack_a_cpy)->content);
		mem = (*stack_a_cpy)->next;
		i = 0;
		while (mem)
		{
			if (*(mem->content) < n)
				i++;
			mem = mem->next;
		}
		*((*stack_a)->content) = i;
		ft_pb(stack_a, stack_b);
		ft_ra(stack_a_cpy);
	}
	while (ft_lstsize_d_lst(*stack_b))
		ft_pa(stack_a, stack_b);
	ft_lstclear_d_lst(stack_a_cpy);
}

int ft_calc_fastest_number(d_list **stack_b, int min, int max)
{
	int *arr;
	int i;
	int fast;

	arr = malloc(sizeof(int) * 4);
	arr[0] = 0 + max;
	arr[1] = 0 + min;
	arr[2] = ft_lstsize_d_lst(*stack_b) - max;
	arr[3] = ft_lstsize_d_lst(*stack_b) - min;
	i = 1;
	fast = 0;
	while (i < 4)
	{
		if (arr[i] < arr[fast])
			fast = i;
		i++;
	}
	free(arr);
	return (fast);
}

void ft_sortb_section(d_list **stack_a, d_list **stack_b, s_sort *sort_o)
{
	int step;
	int min;
	int max;
	int f_max;

	f_max = ft_find_max_lst(*stack_b);
	while (ft_lstsize_d_lst(*stack_b))
	{
		min = ft_find_min_pos_lst(*stack_b);
		max = ft_find_max_pos_lst(*stack_b);
		step = ft_calc_fastest_number(stack_b, min, max);
		// bring max to top by going up
		if (!step)
			while (ft_find_max_pos_lst(*stack_b))
				ft_update_sort_score(sort_o, "6", stack_a, stack_b);
		if (step == 1)
			while (ft_find_min_pos_lst(*stack_b))
				ft_update_sort_score(sort_o, "6", stack_a, stack_b);
		if (step == 2)
			while (ft_find_max_pos_lst(*stack_b))
				ft_update_sort_score(sort_o, "8", stack_a, stack_b);
		if (step == 3)
			while (ft_find_min_pos_lst(*stack_b))
				ft_update_sort_score(sort_o, "8", stack_a, stack_b);
		if (step == 1 || step == 3)
		{
			ft_update_sort_score(sort_o, "3", stack_a, stack_b);
			ft_update_sort_score(sort_o, "5", stack_a, stack_b);
		}
		if (step == 0 || step == 2)
			ft_update_sort_score(sort_o, "3", stack_a, stack_b);
	}
	while (f_max != *(ft_lstlast_d_lst(*stack_a)->content))
		ft_update_sort_score(sort_o, "5", stack_a, stack_b);
}


// (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)

// free split argv[1] strings
void ft_free_split(char **mem)
{
	int i;

	i = -1;
	while (mem[++i])
		free(mem[i]);
	free(mem);
}

// function to compare sorting algorithms
int ft_compare_algorithm_scores(s_sort **sort_scores, int test)
{
	int moves;
	int i;
	int j;

	i = 0;
	j = 0;
	moves = (sort_scores[i])->n_moves;
	while (sort_scores[i])
	{
		if ((sort_scores[i])->n_moves < moves)
		{
			if (i == 1 && test == 3)
				i = i;
			else
			{
				moves = (sort_scores[i])->n_moves;
				j = i;
			}
		}
		i++;
	}
	return (j);
}

// function to test algorithms whithout having to create a stack for each algorithm
void ft_test_algorithm(s_sort *sort_s, d_list **stack_a, void (*f)(d_list**, d_list**, s_sort*))
{
	d_list **stack_a_cpy;
	d_list **stack_b_cpy;

	stack_b_cpy = malloc(sizeof(d_list*));
	*stack_b_cpy = NULL;

	stack_a_cpy = ft_make_lst_cpy(stack_a_cpy, *stack_a);
	(*f)(stack_a_cpy, stack_b_cpy, sort_s);

	ft_lstclear_d_lst(stack_a_cpy);
	free(stack_b_cpy);
}

void ft_free_sort_scores(s_sort **sort_scores)
{
	s_sort **ex;

	ex = sort_scores;
	while (*sort_scores)
	{
		if ((*sort_scores)->moves_str)
			free((*sort_scores)->moves_str);
		free(*sort_scores);
		sort_scores++;
	}
	free(ex);	
}

void ft_print_move(char a)
{
	if (a == '1')
		printf("sa\n");
	else if (a == '2')
		printf("sb\n");
	else if (a == '3')
		printf("pa\n");
	else if (a == '4')
		printf("pb\n");
	else if (a == '5')
		printf("ra\n");
	else if (a == '6')
		printf("rb\n");
	else if (a == '7')
		printf("rra\n");
	else if (a == '8')
		printf("rrb\n");
}

// (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)
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

// gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg
int main (int argc, char **argv)
{
	s_sort **sort_scores;
	s_sort **ex;
	int x;

	d_list **stack_a;
	char **mem;
	// Checking for parameters errors (1 - there are non integers) (2 - bigger than integer) (3 - to many arguments) (4 - there are duplicates)
	if (ft_check_parameters(argc, argv, 0) && ft_check_parameters(argc, argv, 0) != 5)
		return (printf("error\n"));
	if (ft_check_parameters(argc, argv, 0) == 5)
		mem = ft_split(argv[1], ' ');
	if (ft_check_parameters(argc, argv, 0) == 5 && ft_check_parameters(argc, mem, 1))
	{
		ft_free_split(mem);
		return (printf("error\n"));
	}
	if (ft_check_parameters(argc, argv, 0) == 5)
		stack_a = ft_collect_integers(argc, mem, 0);
	else
		stack_a = ft_collect_integers(argc, argv, 1);

	// malloc for sort_scores array
	sort_scores = malloc(sizeof(s_sort*) * 2);
	sort_scores[1] = NULL;

	// initialising sort_scores
	x = 0;
	while (x < 1)
	{
		sort_scores[x] = malloc(sizeof(s_sort));
		(sort_scores[x])->n_moves = 0;
		(sort_scores[x])->moves_str = NULL;
		x++;
	}
	
	if (!ft_list_sorted(*stack_a, 0))
	{
		if (ft_lstsize_d_lst(*stack_a) <= 3)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack_less3);
		else if (ft_lstsize_d_lst(*stack_a) < 40)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack_less5);
		else if (ft_lstsize_d_lst(*stack_a) <= 60)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack7);
		else if (ft_lstsize_d_lst(*stack_a) <= 499)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack8);
		else if (ft_lstsize_d_lst(*stack_a) == 500)
			ft_test_algorithm(sort_scores[0], stack_a, ft_sort_stack10);
	}
	if (!ft_list_sorted(*stack_a, 0))
	{
		x = 0;
		while (x < 1)
		{
			if (ft_count_dmoves(sort_scores[x]->moves_str))
				sort_scores[x]->moves_str = ft_edit_movestr(ft_count_dmoves(sort_scores[x]->moves_str), sort_scores[x]->moves_str);
			(sort_scores[x])->n_moves = ft_strlen(sort_scores[x]->moves_str);
			x++;
		}
		printf("-- %i --\n", (sort_scores[0])->n_moves);
	}
	
	if (ft_check_parameters(argc, argv, 0) == 5)
		ft_free_split(mem);
	ft_lstclear_d_lst(stack_a);

	// free sort_scores
	ft_free_sort_scores(sort_scores);

	return (0);
}

// limits
// 3 digits - (max: 3)
// 5 digits - (max: 12)
// 100 digits - (max: 700)
// 500 digits - (max: 5500)