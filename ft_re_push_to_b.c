/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_push_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:07:54 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/12 11:38:44 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_next_num_a(t_list **stack_a, t_list **stack_b)
{
	if (((*stack_a)->index == (((*stack_a)->prev->index) + 1))
		&& ((*stack_a)->prev->class == -1))
	{
		(*stack_a)->class = -1;
		ft_operate_stack(stack_a, stack_b, RA);
		return (1);
	}
	if ((*stack_a)->next == NULL)
		return (0);
	if (((*stack_a)->next->index == (((*stack_a)->prev->index) + 1))
		&& ((*stack_a)->prev->class == -1))
	{
		ft_operate_stack(stack_a, stack_b, SA);
		(*stack_a)->class = -1;
		ft_operate_stack(stack_a, stack_b, RA);
		return (1);
	}
	return (0);
}

int	ft_check_next_num_b_2(t_list **stack_a, t_list **stack_b)
{
	if (((*stack_b)->next->index == (((*stack_a)->prev->index) + 1))
		&& ((*stack_a)->prev->class == -1))
	{
		ft_operate_stack(stack_a, stack_b, SB);
		ft_operate_stack(stack_a, stack_b, PA);
		(*stack_a)->class = -1;
		ft_operate_stack(stack_a, stack_b, RA);
		return (1);
	}	
	if (((*stack_b)->prev->index == (((*stack_a)->prev->index) + 1))
		&& ((*stack_a)->prev->class == -1))
	{
		ft_operate_stack(stack_a, stack_b, RRB);
		ft_operate_stack(stack_a, stack_b, PA);
		(*stack_a)->class = -1;
		ft_operate_stack(stack_a, stack_b, RA);
		return (1);
	}
	return (0);
}

int	ft_check_next_num_b(t_list **stack_a, t_list **stack_b)
{
	if (((*stack_b)->index == (((*stack_a)->prev->index) + 1))
		&& ((*stack_a)->prev->class == -1))
	{
		ft_operate_stack(stack_a, stack_b, PA);
		(*stack_a)->class = -1;
		ft_operate_stack(stack_a, stack_b, RA);
		return (1);
	}	
	if ((*stack_b)->next == NULL)
		return (0);
	if (ft_check_next_num_b_2(stack_a, stack_b))
		return (1);
	return (0);
}

int	ft_check_next_num(t_list **stack_a, t_list **stack_b)
{
	if (stack_a != NULL && (*stack_a) != NULL)
	{
		if (ft_check_next_num_a(stack_a, stack_b))
			return (1);
	}
	if (stack_b != NULL && (*stack_b) != NULL)
	{
		if (ft_check_next_num_b(stack_a, stack_b))
			return (1);
	}
	return (0);
}

void	ft_re_push_to_b(t_list **stack_a, t_list **stack_b)
{
	int		current_class;

	current_class = (*stack_a)->class;
	while ((*stack_a)->class == current_class)
	{
		if (ft_check_next_num(stack_a, stack_b))
			continue ;
		ft_operate_stack(stack_a, stack_b, PB);
	}
}
