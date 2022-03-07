#ifndef PUSH_SWAP
# define PUSH_SWAP

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

size_t	ft_strlen(const char *s);
double ft_atoi_dbl(const char *str);
void ft_print_move(char a);
char	*ft_strjoin(char const *s1, char const *s2);
static int	ft_issep(char s, char c);
static int	countwords(char const *s, char c);
static void	ft_cpywords(char *dest, char *src, char c);
static void	do_the_split(char **matriz, char *s, char c);
char	**ft_split(char const *s, char c);
d_list *ft_lstnew_d_lst(void *content);
void ft_lstadd_front_d_lst(d_list **lst, d_list *new);
int ft_lstsize_d_lst(d_list *lst);
d_list *ft_lstlast_d_lst(d_list *lst);
void ft_lstadd_back_d_lst(d_list **lst, d_list *new);
void ft_lstclear_d_lst(d_list **lst);
void	ft_lstdelone(d_list *lst, void (*del)(void*));
void ft_sa(d_list *stack);
void ft_sb(d_list *stack);
void ft_ss(d_list *stack_a, d_list *stack_b);
void ft_pa(d_list **stack_a, d_list **stack_b);
void ft_pb(d_list **stack_a, d_list **stack_b);
void ft_ra(d_list **stack);
void ft_rb(d_list **stack);
void ft_rr(d_list **stack_a, d_list **stack_b);
void ft_rra(d_list **stack);
void ft_rrb(d_list **stack);
void ft_rrr(d_list **stack_a, d_list **stack_b);
int ft_list_sorted(d_list *stack, int j);
int ft_str_arr_size(char **argv);
int ft_check_parameters(int argc, char **argv, int k);
d_list **ft_collect_integers(int argc, char **argv, int k);
d_list **ft_make_lst_cpy(d_list **stack_a_cpy, d_list *stack_a_orig);
void ft_change_lst(char move, d_list **stack_a, d_list **stack_b);
void ft_print_linked_list(d_list *stack_a);
void ft_sort_stack0(d_list **stack_a, d_list **stack_b, s_sort *sort_0);
int ft_find_min_pos_lst(d_list *stack);
void ft_update_sort_score(s_sort *sort_s, char *move, d_list **stack_a, d_list **stack_b);
void ft_sort_stack_less3(d_list **stack_a, d_list **stack_b, s_sort *sort_1);
void ft_sort_stack_less5(d_list **stack_a, d_list **stack_b, s_sort *sort_2);
void ft_sort_stack8(d_list **stack_a, d_list **stack_b, s_sort *sort_8);
int ft_find_max_pos_lst(d_list *stack);
int ft_find_max_lst(d_list *stack);
int ft_find_min_lst(d_list *stack);
int ft_average_lst(d_list *stack);
void ft_sort_stack4(d_list **stack_a, d_list **stack_b, s_sort *sort_4);
int ft_lower_then(d_list *stack, int i);
int ft_bigger_then(d_list *stack, int i);
int ft_equal_to(d_list *stack, int i);
int ft_arr_size(int *arr);
int *ft_resize_arr(int *arr, int num, int action, int *size);
int ft_arr_last(int *arr, int *size);
int ft_avg_until_min(d_list *stack, int min);
void ft_print_avgs(int *arr, int size);
int *ft_calc_route(d_list **stack_a, d_list **stack_b);
void ft_make_range(d_list **stack_a, d_list **stack_b);
int ft_calc_fastest_number(d_list **stack_b, int min, int max);
void ft_sortb_section(d_list **stack_a, d_list **stack_b, s_sort *sort_o);
void ft_sort_stack7(d_list **stack_a, d_list **stack_b, s_sort *sort_7);
void ft_sort_stack9(d_list **stack_a, d_list **stack_b, s_sort *sort_9);
void ft_sort_stack10(d_list **stack_a, d_list **stack_b, s_sort *sort_10);
void ft_free_split(char **mem);
int ft_compare_algorithm_scores(s_sort **sort_scores, int test);
void ft_test_algorithm(s_sort *sort_s, d_list **stack_a, void (*f)(d_list**, d_list**, s_sort*));
void ft_free_sort_scores(s_sort **sort_scores);
void ft_print_move(char a);
int ft_count_dmoves(char *str);
char *ft_edit_movestr(int times, char *str);
void ft_small_half_to_b(d_list **stack_a, d_list **stack_b, s_sort *sort_p, int value);

#endif