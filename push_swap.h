/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:08:26 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/13 21:27:07 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define NOTHING 12

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				num;
	int				index;
	int				class;
}				t_list;

int		ft_putnbr(int nb);

/*
** ft_pass_argument.c
*/
t_list	*ft_pass_argument(int argc, char **argv);
void	ft_check_duplicate(t_list *head, int value);
int		ft_atoi_for_pushswap(const char *str, t_list *head);
/*
** ft_error.c
*/
void	ft_error(void);

/*
** ft_operate.c
*/
void	ft_operate(t_list **stack_a, t_list **stack_b);
void	ft_label_stack(t_list **stack);
int		ft_check_sort(t_list *stack);

/*
** ft_operate_under_three.c
*/
void	ft_operate_under_three(t_list **stack, char which_stack);
void	ft_operate_two(t_list **stack, char which_stack);

/*
** ft_operate_three.c
*/
void	ft_operate_three(t_list **stack, char which_stack);
void	ft_second_first_third(t_list **stack, char which_stack);
void	ft_second_third_first(t_list **stack, char which_stack);
void	ft_first_third_second(t_list **stack, char which_stack);
void	ft_first_second_third(t_list **stack, char which_stack);

/*
** ft_stack_utils.c
*/
t_list	*ft_new_stack(int num, int index, int class);
t_list	*ft_pop_stack(t_list **stack);
void	ft_push_back_stack(t_list **head, int num, int index, int class);
void	ft_push_front_stack(t_list **head, int num, int index, int class);
int		ft_stack_len(t_list *head);

/*
** ft_stack_utils_2.c
*/
int		ft_find_max_index(t_list *stack);
int		ft_find_min_index(t_list *stack);
void	ft_free_stack(t_list **target);

/*
** ft_operate_stack.c
*/
void	ft_swap_stack(t_list **stack);
void	ft_rotate_stack(t_list **stack);
void	ft_reverse_rotate_stack(t_list **stack);
void	ft_push_stack(t_list **src, t_list **dest);
void	ft_operate_stack(t_list **stack_a, t_list **stack_b, int command);

/*
** ft_operate_under_three.c
*/
void	ft_operate_under_three(t_list **stack, char which_stack);
void	ft_operate_two(t_list **stack, char which_stack);

/*
** ft_operate_under_six.c
*/
int		ft_find_index_place(t_list *stack, int index);
void	ft_cut_to_three(t_list **main_stack, t_list **sub_stack, char which);
void	ft_push_remain(t_list **main_stack, t_list **sub_stack, char which);
void	ft_operate_under_six(t_list **stack_a, t_list **stack_b,
			char which_stack);

/*
** ft_ft_re_push_to_a.c
*/
void	ft_check_rotatable(t_list **stack_a, t_list **stack_b, char which);
void	ft_split_w_median(t_list **stack_a, t_list **stack_b, int median);
void	ft_re_push_to_a(t_list **stack_a, t_list **stack_b);

/*
** ft_ft_re_push_to_b.c
*/
int		ft_check_next_num_a(t_list **stack_a, t_list **stack_b);
int		ft_check_next_num_b_2(t_list **stack_a, t_list **stack_b);
int		ft_check_next_num_b(t_list **stack_a, t_list **stack_b);
int		ft_check_next_num(t_list **stack_a, t_list **stack_b);
void	ft_re_push_to_b(t_list **stack_a, t_list **stack_b);

/*
** ft_operate_quick_sort.c
*/
void	ft_operate_quick_sort(t_list **stack_a, t_list **stack_b);
void	ft_init_quick_sort(t_list **stack_a, t_list **stack_b);

/*
** ft_save_command.c
*/
int		ft_command_merge_2(int first, int second, t_list **tmp);
int		ft_command_merge(int first, int second, t_list **tmp);
void	ft_merge_command(t_list **stack);
t_list	*ft_save_command_to_chain(int mem[]);
void	ft_save_command(int command, int output);

/*
** ft_operate_print.c
*/
void	ft_print_command(int i);
void	ft_operate_print(t_list **command);

/*
** ft_utils.c
*/
int		ft_putnbr(int nb);
int		ft_putchar(char c);

void	ft_print_list(t_list *head);

#endif
