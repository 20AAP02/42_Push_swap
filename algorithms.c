#include <push_swap.h>

// sort algrithm for lists of 3 numbers
void ft_sort_stack_less3(d_list **stack_a, d_list **stack_b, s_sort *sort_1)
{
	int mem1;
	int mem2;
	int mem3;

	if (ft_lstsize_d_lst(*stack_a) == 2)
		ft_update_sort_score(sort_1, "1", stack_a, stack_a);
	else if (ft_lstsize_d_lst(*stack_a) > 3)
		return ;
	else
	{
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
}

// sort algrithm for lists of 5 numbers
void ft_sort_stack_less5(d_list **stack_a, d_list **stack_b, s_sort *sort_2)
{
	int max;
	d_list *mem;
	int pos;

	if (ft_list_sorted(*stack_a, 0))
		return ;
	while (ft_lstsize_d_lst(*stack_a) > 3)
	{
		pos = ft_find_min_pos_lst(*stack_a);
		if (pos <= (ft_lstsize_d_lst(*stack_a) / 2))
			while (ft_find_min_pos_lst(*stack_a) != 0)
				ft_update_sort_score(sort_2, "5", stack_a, stack_a);
		else
			while (ft_find_min_pos_lst(*stack_a) != 0)
				ft_update_sort_score(sort_2, "7", stack_a, stack_a);
		ft_update_sort_score(sort_2, "4", stack_a, stack_b);
	}
	ft_sort_stack_less3(stack_a, stack_b, sort_2);
	while (ft_lstsize_d_lst(*stack_b))
		ft_update_sort_score(sort_2, "3", stack_a, stack_b);
}

// sorting algrithm for lists of 50 numbers (function that devides the list in 2)
void ft_sort_stack7(d_list **stack_a, d_list **stack_b, s_sort *sort_7)
{
	int half;
	int check;

	check = 0;
	ft_make_range(stack_a, stack_b);
	if (ft_lstsize_d_lst(*stack_a) % 2)
		check = 1;
	half = ft_lstsize_d_lst(*stack_a) / 2;
	ft_small_half_to_b(stack_a, stack_b, sort_7, half);
	ft_sortb_section(stack_a, stack_b, sort_7);
	while (ft_lstsize_d_lst(*stack_a) != 0)
		ft_update_sort_score(sort_7, "4", stack_a, stack_b);
	ft_sortb_section(stack_a, stack_b, sort_7);
}

// sorting algorithm for lists of 100 numbers (function that devides the list in 4)
void ft_sort_stack8(d_list **stack_a, d_list **stack_b, s_sort *sort_8)
{
	int half;

	ft_make_range(stack_a, stack_b);
	half = ft_lstsize_d_lst(*stack_a) / 2;
	ft_small_half_to_b(stack_a, stack_b, sort_8, half);
	half = ft_lstsize_d_lst(*stack_b) / 2;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if (*((*stack_b)->content) >= half)
			ft_update_sort_score(sort_8, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_8, "6", stack_a, stack_b);
	}
	ft_sortb_section(stack_a, stack_b, sort_8);

	// quarter sorted

	half = ft_lstsize_d_lst(*stack_a) / 2;
	ft_small_quarter_to_b(stack_a, stack_b, sort_8, half);
	ft_sortb_section(stack_a, stack_b, sort_8);

	// half sorted

	while (*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_8, "4", stack_a, stack_b);
	half = ft_lstsize_d_lst(*stack_b) / 2;
	ft_big_quarter_to_a(stack_a, stack_b, sort_8, half);
	ft_sortb_section(stack_a, stack_b, sort_8);

	// 3 quarters sorted

	while (*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_8, "4", stack_a, stack_b);
	ft_sortb_section(stack_a, stack_b, sort_8);
}

// sorting algorithm for lists of until 400 numbers (function that devides the list in 8)
void ft_sort_stack9(d_list **stack_a, d_list **stack_b, s_sort *sort_9)
{
	int half;
	int size;

	ft_make_range(stack_a, stack_b);

	// transfer smallest half of the list to stack b
	half = ft_lstsize_d_lst(*stack_a) / 2;
	while (ft_lstsize_d_lst(*stack_a) > half)
	{
		if (*((*stack_a)->content) < half)
			ft_update_sort_score(sort_9, "4", stack_a, stack_b);
		else
			ft_update_sort_score(sort_9, "5", stack_a, stack_b);
	}
	// transfer biggest quarter of stack b to stack a 
	half = ft_lstsize_d_lst(*stack_b) / 2;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if (*((*stack_b)->content) >= half)
			ft_update_sort_score(sort_9, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_9, "6", stack_a, stack_b);
	}
	// transfer half quarter of b to stack a
	half = ft_lstsize_d_lst(*stack_b) / 2;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if (*((*stack_b)->content) >= half)
			ft_update_sort_score(sort_9, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_9, "6", stack_a, stack_b);
	}
	// sort stack b
	// here half is merely being used so to not create another variable
	ft_sortb_section(stack_a, stack_b, sort_9);
	// transfer half quarter of a to stack b
	half = ft_lstsize_d_lst(*stack_a) / 4;
	while (*((*stack_a)->content) < half)
		ft_update_sort_score(sort_9, "4", stack_a, stack_b);
	// sort stack b
	ft_sortb_section(stack_a, stack_b, sort_9);
	// quarter sorted

	half = ft_lstsize_d_lst(*stack_a) / 2;
	while (*((*stack_a)->content) < half)
		ft_update_sort_score(sort_9, "4", stack_a, stack_b);

	// transfer half quarter of b to stack a
	size = ft_lstsize_d_lst(*stack_b);
	half = size / 2;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if (*((*stack_b)->content) >= (half + size))
			ft_update_sort_score(sort_9, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_9, "6", stack_a, stack_b);
	}
	// sort b
	ft_sortb_section(stack_a, stack_b, sort_9);
	// transfer half quarter of a to stack b
	half = ft_lstsize_d_lst(*stack_a) / 2;
	while (*((*stack_a)->content) < half)
		ft_update_sort_score(sort_9, "4", stack_a, stack_b);
	// sort b
	ft_sortb_section(stack_a, stack_b, sort_9);
	// half sorted

	while (*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_9, "4", stack_a, stack_b);
	
	// transfer biggest quarter of stack b to stack a 
	half = ft_lstsize_d_lst(*stack_b) / 2;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if (*((*stack_b)->content) >= (half * 3))
			ft_update_sort_score(sort_9, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_9, "6", stack_a, stack_b);
	}
	// transfer half quarter of b to stack a
	size = half;
	half = ft_lstsize_d_lst(*stack_b) / 2;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if (*((*stack_b)->content) >= (size * 2) + half)
			ft_update_sort_score(sort_9, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_9, "6", stack_a, stack_b);
	}
	// sort b
	ft_sortb_section(stack_a, stack_b, sort_9);
	size = (ft_lstsize_d_lst(*stack_a) / 4) * 3;
	// transfer half quarter of a to stack b
	while (*((*stack_a)->content) < size)
		ft_update_sort_score(sort_9, "4", stack_a, stack_b);
	// sort b
	ft_sortb_section(stack_a, stack_b, sort_9);
	while (*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_9, "4", stack_a, stack_b);
	
	size = ft_lstsize_d_lst(*stack_b);
	half = size / 2;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if (*((*stack_b)->content) >= (size * 3) + half)
			ft_update_sort_score(sort_9, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_9, "6", stack_a, stack_b);
	}
	// sort b
	ft_sortb_section(stack_a, stack_b, sort_9);
	
	while (*((*stack_a)->content) != 0)
	{
		if (*((*stack_a)->content) == *(ft_lstlast_d_lst(*stack_a)->content) + 1)
			ft_update_sort_score(sort_9, "5", stack_a, stack_b);
		else
			ft_update_sort_score(sort_9, "4", stack_a, stack_b);
	}
	// sort b
	ft_sortb_section(stack_a, stack_b, sort_9);
}

// (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)
// sorting algorithm for lists of bigger or equal than 400 numbers (function that devides the list in 16)
void ft_sort_stack10(d_list **stack_a, d_list **stack_b, s_sort *sort_10)
{
	int half;
	int check;
	int i;

	ft_make_range(stack_a, stack_b);
	// (1)
	i = 0;
	half = ft_lstsize_d_lst(*stack_a) / 2;
	while (ft_lstsize_d_lst(*stack_a) > half)
	{
		if ((half * 2) + 1 < i)
			break ;
		if (*((*stack_a)->content) < half)
			ft_update_sort_score(sort_10, "4", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "5", stack_a, stack_b);
		i++;
	}
	// (2) 
	half = ft_lstsize_d_lst(*stack_b) / 2;
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if ((half * 2) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= half)
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (3) 
	half = ft_lstsize_d_lst(*stack_b) / 2;
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if ((half * 2) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= half)
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (4)
	half = ft_lstsize_d_lst(*stack_b) / 2;
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if ((half * 2) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= half)
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (5) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);

	// 1 sixteenth sorted

    // (6)
	half = ft_lstsize_d_lst(*stack_a) / 8;
	while (*((*stack_a)->content) < half)
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (7) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);
	
	// 1 eight sorted
	// (8)
	
	half = ft_lstsize_d_lst(*stack_a) / 4;
	while (*((*stack_a)->content) < half)
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (9)
	half = ft_lstsize_d_lst(*stack_b) / 2;
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half)
	{
		if ((half * 2) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= (half * 3))
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (10) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);
	
	// 3 sixteenth sorted

	// (11)
	half = ft_lstsize_d_lst(*stack_a) / 4;
	while (*((*stack_a)->content) < half)
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (12) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);

	// 1 quarter sorted

	// (13)
	half = ft_lstsize_d_lst(*stack_a) / 2;
	while (*((*stack_a)->content) < half)
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (14)
	half = ft_lstsize_d_lst(*stack_b);
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > (half / 2))
	{
		if (half < i)
			break ;
		if (*((*stack_b)->content) >= (half + (half / 2)) )
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (15)
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > (half / 4))
	{
		if ((half / 2) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= (half + (half / 4)) )
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;	
	}
	// (16) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);
	
	// 5 sixteenth sorted

	// (17)
	while (*((*stack_a)->content) < (half + (half / 2)))
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (18) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);
	
	// 3 eights sorted
	
	// (19)
	half = ft_lstsize_d_lst(*stack_a);
	while (*((*stack_a)->content) < (half / 2))
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (20)
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > (half / 16))
	{
		if ((half / 8) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= ((half / 16) + (half / 4) + (half / 8) + 1) )
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (21) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);
	
	// 7 sixteenth sorted

	// (22)
	while(*((*stack_a)->content) < (half / 2))
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (23) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);

	
	// half sorted


	// (24)
	while(*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (25)
	half = ft_lstsize_d_lst(*stack_b);
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half / 2)
	{
		if (half + 1 < i)
			break ;
		if (*((*stack_b)->content) >= (half + (half / 2)))
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (26)
	half = ft_lstsize_d_lst(*stack_b);
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half / 2)
	{
		if (half + 1 < i)
			break ;
		if (*((*stack_b)->content) >= ((half * 2) + (half / 2)))
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (27)
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half / 4)
	{
		if ((half / 2) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= ((half * 2) + (half / 4) + 1))
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (28) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);
	
	//ft_print_linked_list(*stack_a);
	//printf("-- %i --\n", ft_list_sorted(*stack_a, 1));
	
	// 9 sixteenth sorted
	
	// (29)
	while(*((*stack_a)->content) < ((half * 2) + (half / 2)))
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);

	// (30) sort stack b
	//printf("-- %i --\n", ft_lstsize_d_lst(*stack_b));

	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);

	// (31)
	while(*((*stack_a)->content) < (half * 3))
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	//ft_print_linked_list(*stack_b);
	// (32)
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half / 4)
	{
		if ((half / 2) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= ((half * 2) + (half / 4) + (half / 2)))
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (33) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);
	
	// 11 sixteenth sorted
	
	// (34)
	while(*((*stack_a)->content) < (half * 3))
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (35) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);
	
	// 3 quarters sorted

	// (36)
	while(*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (37)
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half / 2)
	{
		if (half + 1 < i)
			break ;
		if (*((*stack_b)->content) >= ((half * 3) + (half / 2)))
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (38)
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half / 4)
	{
		if ((half / 2) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= ((half * 3) + (half / 4)))
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (39) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);
	
	// 13 sixteenth sorted

	// (40)
	while(*((*stack_a)->content) < ((half * 3) + (half / 2)))
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (41) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);

	// 7 eights sorted

	// (42)
	while(*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (43)
	i = 0;
	while (ft_lstsize_d_lst(*stack_b) > half / 4)
	{
		if ((half / 2) + 1 < i)
			break ;
		if (*((*stack_b)->content) >= ((half * 3) + (half / 2) + (half / 4)))
			ft_update_sort_score(sort_10, "3", stack_a, stack_b);
		else
			ft_update_sort_score(sort_10, "6", stack_a, stack_b);
		i++;
	}
	// (44) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);

	// 15 sixteenth sorted

	// (45)
	while(*((*stack_a)->content) != 0)
		ft_update_sort_score(sort_10, "4", stack_a, stack_b);
	// (46) sort stack b
	if (ft_lstsize_d_lst(*stack_b))
		ft_sortb_section(stack_a, stack_b, sort_10);

	// Sorted
	//ft_print_linked_list(*stack_a);
	printf("-- %i --\n", ft_list_sorted(*stack_a, 1));
}
