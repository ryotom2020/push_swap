# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 09:52:29 by rtomiki           #+#    #+#              #
#    Updated: 2021/07/13 21:27:17 by rtomiki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c ft_operate.c ft_operate_stack.c ft_operate_under_three.c \
		ft_operate_three.c ft_operate_under_six.c ft_operate_quick_sort.c \
		ft_re_push_to_a.c ft_re_push_to_b.c ft_save_command.c ft_stack_utils.c \
		ft_stack_utils_2.c ft_error.c ft_pass_argument.c ft_operate_print.c ft_utils.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRCS)
	@gcc -o $(NAME) $(OBJS)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re