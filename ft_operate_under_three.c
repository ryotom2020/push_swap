/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_under_three.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:43:59 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/12 10:34:42 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operate_two(t_list **stack, char which_stack)
{
	if ((*stack)->num > (*stack)->next->num)
	{
		if (which_stack == 'A')
			ft_operate_stack(stack, NULL, SA);
		else
			ft_operate_stack(NULL, stack, SB);
	}
}

void	ft_operate_under_three(t_list **stack, char which_stack)
{
	int	stack_len;

	stack_len = ft_stack_len(*stack);
	if (stack_len == 2)
		ft_operate_two(stack, which_stack);
	if (stack_len == 3)
		ft_operate_three(stack, which_stack);
}
