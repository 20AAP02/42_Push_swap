CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM	= rm -f

NAME	= libft.a

INCLUDE0	= ft_printf/
INCLUDE1	= 42_libft/
INCLUDE2	= pushswap/

FT_PRINTF	= ft_printf/ft_printf_functions0.c ft_printf/ft_printf_functions1.c ft_printf/ft_printf_functions2.c \
					ft_printf/ft_printf_functions3.c ft_printf/ft_printf_functions4.c ft_printf/ft_printf_functions5.c \
					ft_printf/ft_printf_functions6.c ft_printf/ft_printf.c
PRINTF_OBJ	= $(FT_PRINTF:.c=.o)

LIBFT	= 42_libft/ft_isascii.c 42_libft/ft_isprint.c 42_libft/ft_isalpha.c 42_libft/ft_isdigit.c 42_libft/ft_isalnum.c \
					42_libft/ft_tolower.c 42_libft/ft_toupper.c 42_libft/ft_strlen.c 42_libft/ft_strlcpy.c 42_libft/ft_strlcat.c \
					42_libft/ft_memset.c 42_libft/ft_bzero.c 42_libft/ft_memcpy.c 42_libft/ft_memmove.c 42_libft/ft_striteri.c \
					42_libft/ft_memchr.c 42_libft/ft_memcmp.c 42_libft/ft_strdup.c 42_libft/ft_calloc.c 42_libft/ft_itoa.c \
					42_libft/ft_putchar_fd.c 42_libft/ft_putstr_fd.c 42_libft/ft_putendl_fd.c 42_libft/ft_putnbr_fd.c \
					42_libft/ft_substr.c 42_libft/ft_strjoin.c 42_libft/ft_strtrim.c 42_libft/ft_split.c 42_libft/ft_strmapi.c \
					42_libft/ft_lstsize.c 42_libft/ft_lstlast.c 42_libft/ft_lstadd_front.c 42_libft/ft_lstadd_back.c \
					42_libft/ft_lstnew.c 42_libft/ft_lstdelone.c 42_libft/ft_lstclear.c 42_libft/ft_lstiter.c 42_libft/ft_lstmap.c
LIB_OBJ	= $(LIBFT:.c=.o)

PUSH_SWAP	= pushswap/algorithms/sort_less_3.c pushswap/algorithms/sort_less_5.c pushswap/algorithms/sort_less_60.c \
					pushswap/algorithms/sort_less_499.c pushswap/algorithms/sort_less_500.c \
					pushswap/list_functions/ft_lstadd_back_d_lst.c pushswap/list_functions/ft_lstadd_front_d_lst.c \
					pushswap/list_functions/ft_lstclear_d_lst.c pushswap/list_functions/ft_lstlast_d_lst.c \
					pushswap/list_functions/ft_lstnew_d_lst.c pushswap/list_functions/ft_lstsize_d_lst.c \
					pushswap/operation_functions/ft_pa.c pushswap/operation_functions/ft_pb.c pushswap/operation_functions/ft_ra.c \
					pushswap/operation_functions/ft_rb.c pushswap/operation_functions/ft_rr.c pushswap/operation_functions/ft_rra.c \
					pushswap/operation_functions/ft_rrb.c pushswap/operation_functions/ft_rrr.c pushswap/operation_functions/ft_sa.c \
					pushswap/operation_functions/ft_sb.c pushswap/operation_functions/ft_ss.c pushswap/push_swap_funcs/ft_atoi_dbl.c \
					pushswap/push_swap_funcs/ft_big_quarter_to_a.c pushswap/push_swap_funcs/ft_calc_fastest_number.c \
					pushswap/push_swap_funcs/ft_change_lst.c pushswap/push_swap_funcs/ft_check_parameters.c \
					pushswap/push_swap_funcs/ft_collect_integers.c pushswap/push_swap_funcs/ft_count_dmoves.c \
					pushswap/push_swap_funcs/ft_edit_movestr.c pushswap/push_swap_funcs/ft_find_max_lst.c \
					pushswap/push_swap_funcs/ft_find_max_pos_lst.c pushswap/push_swap_funcs/ft_find_min_lst.c \
					pushswap/push_swap_funcs/ft_find_min_pos_lst.c pushswap/push_swap_funcs/ft_free_sort_scores.c \
					pushswap/push_swap_funcs/ft_free_split.c pushswap/push_swap_funcs/ft_list_sorted.c \
					pushswap/push_swap_funcs/ft_make_lst_cpy.c pushswap/push_swap_funcs/ft_make_range.c \
					pushswap/push_swap_funcs/ft_print_linked_list.c pushswap/push_swap_funcs/ft_print_move.c \
					pushswap/push_swap_funcs/ft_small_half_to_b.c pushswap/push_swap_funcs/ft_small_quarter_to_b.c \
					pushswap/push_swap_funcs/ft_sortb_section.c pushswap/push_swap_funcs/ft_test_algorithm.c \
					pushswap/push_swap_funcs/ft_update_sort_score.c pushswap/push_swap_funcs/ft_str_arr_size.c \
					pushswap/algorithms/sort_500_funcs/part1.c pushswap/algorithms/sort_500_funcs/part2.c
PUSH_SWAP_OBJ	= $(PUSH_SWAP:.c=.o)

all:	$(NAME) clean

$(NAME):	compile $(PRINTF_OBJ) $(LIB_OBJ) $(PUSH_SWAP_OBJ) $(INCLUDE0) $(INCLUDE1) $(INCLUDE2)
	$(LIB1) $(NAME) $(PRINTF_OBJ) $(LIB_OBJ) $(PUSH_SWAP_OBJ)
	$(LIB2) $(NAME)
	$(CC) $(CFLAGS) pushswap.c libft.a -o push_swap
	rm libft.a
	echo "Done"

compile:
	echo "Compiling everything..."
compile_libft:
	echo "Compiling libft..."
compile_ft_printf:
	echo "Compiling ft_printf..."

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE0) -I$(INCLUDE1) -I$(INCLUDE2) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(LIB_OBJ) $(PUSH_SWAP_OBJ) $(PRINTF_OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) push_swap

l: libft clean

f: ft_printf clean

libft: compile_libft $(LIB_OBJ) $(INCLUDE1)
	$(LIB1) $(NAME) $(LIB_OBJ)
	$(LIB2) $(NAME)
	echo "Done"

ft_printf: compile_ft_printf $(PRINTF_OBJ) $(INCLUDE0)
	$(LIB1) $(NAME) $(PRINTF_OBJ)
	$(LIB2) $(NAME)
	echo "Done"

re: all clean

.PHONY: all
