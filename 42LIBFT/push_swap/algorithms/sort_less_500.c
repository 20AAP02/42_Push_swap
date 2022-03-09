#include "../../42_libft/libft.h"
#include "../push_swap.h"

// sorting algorithm for lists of bigger or equal than 400 numbers (function that devides the list in 16)
void ft_sort_stack10(d_list **stack_a, d_list **stack_b, s_sort *sort_10)
{
	int half;
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
}
