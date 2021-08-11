/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:41:43 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/12 11:16:35 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_stack(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
}

void	ft_swap_stack(t_list **stack)
{
	t_list	*head;
	t_list	*first;
	t_list	*second;

	head = *stack;
	if (head == NULL || head->next == NULL)
		return ;
	if (head->prev == head->next)
		ft_rotate_stack(stack);
	else
	{
		second = ft_pop_stack(stack);
		first = ft_pop_stack(stack);
		ft_push_front_stack(stack, second->num, second->index, second->class);
		ft_push_front_stack(stack, first->num, first->index, first->class);
		free(first);
		free(second);
	}
}

void	ft_reverse_rotate_stack(t_list **stack)
{
	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
	*stack = (*stack)->prev;
}

void	ft_push_stack(t_list **src, t_list **dest)
{
	t_list	*src_head;
	t_list	*add;

	src_head = *src;
	if (src_head == NULL)
		return ;
	add = ft_pop_stack(src);
	if (add == NULL)
		return ;
	ft_push_front_stack(dest, add->num, add->index, add->class);
	free(add);
}

void	ft_operate_stack(t_list **stack_a, t_list **stack_b, int command)
{
	if (command == SA || command == SS)
		ft_swap_stack(stack_a);
	if (command == RA || command == RR)
		ft_rotate_stack(stack_a);
	if (command == RRA || command == RRR)
		ft_reverse_rotate_stack(stack_a);
	if (command == PA)
		ft_push_stack(stack_b, stack_a);
	if (command == SB || command == SS)
		ft_swap_stack(stack_b);
	if (command == RB || command == RR)
		ft_rotate_stack(stack_b);
	if (command == RRB || command == RRR)
		ft_reverse_rotate_stack(stack_b);
	if (command == PB)
		ft_push_stack(stack_a, stack_b);
	ft_save_command(command, 0);
	(void)stack_b;
}
