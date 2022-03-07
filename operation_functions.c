#include <push_swap.h>

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
