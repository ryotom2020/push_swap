/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_quick_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:17:22 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/13 21:19:25 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_quick_sort(t_list **stack_a, t_list **stack_b)
{
	int		len;
	int		cnt;

	len = ft_stack_len(*stack_a);
	cnt = 0;
	while (++cnt <= len)
	{
		if ((*stack_a)->index <= len / 2)
			ft_operate_stack(stack_a, stack_b, PB);
		else
			ft_operate_stack(stack_a, stack_b, RA);
	}
}

void	ft_operate_quick_sort(t_list **stack_a, t_list **stack_b)
{
	ft_init_quick_sort(stack_a, stack_b);
	while ((*stack_a)->class != -1 || (*stack_b) != NULL)
	{
		ft_re_push_to_a(stack_a, stack_b);
		if ((*stack_a)->class != -1 || (*stack_b) != NULL)
			ft_re_push_to_b(stack_a, stack_b);
	}
}
