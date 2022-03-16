/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:31:27 by amaria-m          #+#    #+#             */
/*   Updated: 2022/03/16 16:18:59 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// double linked list struct
typedef struct t_dlst
{
	struct t_dlst	*past;
	int				*content;
	struct t_dlst	*next;
}	t_dlst;

typedef struct t_500
{
	int	half;
	int	i;
}	t_500;

// sorting scores struct (1-sa, 2-sb, 3-pa, 4-pb, 5-ra, 6-rb, 7-rra, 8-rrb)
typedef struct t_sort
{
	int		n_moves;
	char	*moves_str;
}	t_sort;

size_t	ft_strlen(const char *s);
double	ft_atoi_dbl(const char *str);
void	ft_print_move(char a);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
t_dlst	*ft_lstnew_d_lst(void *content);
void	ft_lstadd_front_d_lst(t_dlst **lst, t_dlst *new);
int		ft_lstsize_d_lst(t_dlst *lst);
t_dlst	*ft_lstlast_d_lst(t_dlst *lst);
void	ft_lstadd_back_d_lst(t_dlst **lst, t_dlst *new);
void	ft_lstclear_d_lst(t_dlst **lst);
void	ft_sa(t_dlst *stack);
void	ft_sb(t_dlst *stack);
void	ft_ss(t_dlst *stack_a, t_dlst *stack_b);
void	ft_pa(t_dlst **stack_a, t_dlst **stack_b);
void	ft_pb(t_dlst **stack_a, t_dlst **stack_b);
void	ft_ra(t_dlst **stack);
void	ft_rb(t_dlst **stack);
void	ft_rr(t_dlst **stack_a, t_dlst **stack_b);
void	ft_rra(t_dlst **stack);
void	ft_rrb(t_dlst **stack);
void	ft_rrr(t_dlst **stack_a, t_dlst **stack_b);
int		ft_list_sorted(t_dlst *stack);
int		ft_str_arr_size(char **argv);
int		ft_check_parameters(int argc, char **argv, int k);
t_dlst	**ft_collect_integers(int argc, char **argv, int k);
t_dlst	**ft_make_lst_cpy(t_dlst **stack_a_cpy, t_dlst *stack_a_orig);
void	ft_change_lst(char move, t_dlst **stack_a, t_dlst **stack_b);
void	ft_print_linked_list(t_dlst *stack_a);
void	ft_sort_stack0(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_0);
int		ft_find_min_pos_lst(t_dlst *stack);
void	ft_update_sort_score(t_sort *sort_s, char *move, t_dlst **stack_a, t_dlst **stack_b);
void	ft_sort_stack_less3(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_1);
void	ft_sort_stack_less5(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_2);
void	ft_sort_stack8(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_8);
int		ft_find_max_pos_lst(t_dlst *stack);
int		ft_find_max_lst(t_dlst *stack);
int		ft_find_min_lst(t_dlst *stack);
int		ft_average_lst(t_dlst *stack);
void	ft_sort_stack4(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_4);
int		ft_lower_then(t_dlst *stack, int i);
int		ft_bigger_then(t_dlst *stack, int i);
int		ft_equal_to(t_dlst *stack, int i);
int		ft_arr_size(int *arr);
int		*ft_resize_arr(int *arr, int num, int action, int *size);
int		ft_arr_last(int *arr, int *size);
int		ft_avg_until_min(t_dlst *stack, int min);
void	ft_print_avgs(int *arr, int size);
int		*ft_calc_route(t_dlst **stack_a, t_dlst **stack_b);
void	ft_make_range(t_dlst **stack_a, t_dlst **stack_b);
int		ft_calc_fastest_number(t_dlst **stack_b, int min, int max);
void	ft_sortb_section(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_o);
void	ft_sort_stack7(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_7);
void	ft_sort_stack9(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_9);
void	ft_sort_stack10(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
int		ft_free_split(char **mem);
int		ft_compare_algorithm_scores(t_sort **sort_scores, int test);
void	ft_test_algorithm(t_sort *sort_s, t_dlst **stack_a, void (*f)(t_dlst**, t_dlst**, t_sort*));
void	ft_free_sort_scores(t_sort **sort_scores);
void	ft_print_move(char a);
int		ft_count_dmoves(char *str);
char	*ft_edit_movestr(int times, char *str);
void	ft_small_half_to_b(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_p, int value);
void	ft_small_quarter_to_b(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_p, int value);
void	ft_big_quarter_to_a(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_p, int value);
void	ft_radix_sort(t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_p);
t_500	ft_block1(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
t_500	ft_block2(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
t_500	ft_block3(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
t_500	ft_block4(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
t_500	ft_block5(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
t_500	ft_block6(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
t_500	ft_block7(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
t_500	ft_block8(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
t_500	ft_block9(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);
t_500	ft_block10(t_500 ex, t_dlst **stack_a, t_dlst **stack_b, t_sort *sort_);

#endif