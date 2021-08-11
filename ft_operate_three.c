/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:02:09 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/12 10:29:13 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_second_third(t_list **stack, char which_stack)
{
	if (which_stack == 'A')
	{
		ft_operate_stack(stack, NULL, SA);
		ft_operate_stack(stack, NULL, RRA);
	}
	else
	{
		ft_operate_stack(NULL, stack, SB);
		ft_operate_stack(NULL, stack, RRB);
	}
}

void	ft_first_third_second(t_list **stack, char which_stack)
{
	if (which_stack == 'A')
		ft_operate_stack(stack, NULL, RA);
	else
		ft_operate_stack(NULL, stack, RB);
}

void	ft_second_third_first(t_list **stack, char which_stack)
{
	if (which_stack == 'A')
	{
		ft_operate_stack(stack, NULL, SA);
		ft_operate_stack(stack, NULL, RA);
	}
	else
	{
		ft_operate_stack(NULL, stack, SB);
		ft_operate_stack(NULL, stack, RB);
	}
}

void	ft_second_first_third(t_list **stack, char which_stack)
{
	if (which_stack == 'A')
		ft_operate_stack(stack, NULL, RRA);
	else
		ft_operate_stack(NULL, stack, RRB);
}

void	ft_operate_three(t_list **stack, char which_stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->num;
	second = (*stack)->next->num;
	third = (*stack)->next->next->num;
	if (third > first && first > second)
	{
		if (which_stack == 'A')
			ft_operate_stack(stack, NULL, SA);
		else
			ft_operate_stack(NULL, stack, SB);
	}
	if (first > second && second > third)
		ft_first_second_third(stack, which_stack);
	if (first > third && third > second)
		ft_first_third_second(stack, which_stack);
	if (second > third && third > first)
		ft_second_third_first(stack, which_stack);
	if (second > first && first > third)
		ft_second_first_third(stack, which_stack);
}
