/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_push_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:07:03 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/12 11:16:55 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_rotatable(t_list **stack_a, t_list **stack_b, char which)
{
	if (which == 'A')
	{
		if (((*stack_a)->index == ((*stack_a)->prev->index + 1))
			&& ((*stack_a)->prev->class == -1))
		{
			(*stack_a)->class = -1;
			ft_operate_stack(stack_a, stack_b, RA);
		}
	}
	else if (which == 'B')
	{
		if (((*stack_b)->index == (((*stack_a)->prev->index) + 1))
			&& ((*stack_a)->prev->class == -1))
		{
			(*stack_b)->class = -1;
			ft_operate_stack(stack_a, stack_b, PA);
			ft_operate_stack(stack_a, stack_b, RA);
		}
		else
			ft_operate_stack(stack_a, stack_b, RB);
	}
}

void	ft_split_w_median(t_list **stack_a, t_list **stack_b, int median)
{
	int	cnt;
	int	len;
	int	max;

	cnt = 0;
	len = ft_stack_len(*stack_b);
	max = ft_find_max_index(*stack_b);
	while (++cnt <= len)
	{
		if ((*stack_b)->index > median)
		{
			(*stack_b)->class = max;
			ft_operate_stack(stack_a, stack_b, PA);
			ft_check_rotatable(stack_a, stack_b, 'A');
		}
		else
			ft_check_rotatable(stack_a, stack_b, 'B');
	}
}

void	ft_re_push_to_a(t_list **stack_a, t_list **stack_b)
{
	int		median;
	int		flag;

	flag = 1;
	while (flag)
	{
		median = (ft_find_max_index(*stack_b)
				+ ft_find_min_index(*stack_b)) / 2;
		ft_split_w_median(stack_a, stack_b, median);
		if (ft_stack_len(*stack_b) <= 6)
		{
			if (ft_stack_len(*stack_b) <= 3)
				ft_operate_under_three(stack_b, 'B');
			else
				ft_operate_under_six(stack_a, stack_b, 'B');
			while (*stack_b != NULL)
			{
				(*stack_b)->class = -1;
				ft_operate_stack(stack_a, stack_b, PA);
				ft_operate_stack(stack_a, stack_b, RA);
			}
			flag = 0;
		}
	}
}
