/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:34:46 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/13 21:16:08 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_list *stack)
{
	t_list	*tmp;
	t_list	*head_save;
	int		current;

	if (stack == NULL)
		return (1);
	tmp = stack;
	head_save = stack;
	current = stack->num;
	while (1)
	{
		tmp = tmp->next;
		if (tmp == NULL || tmp == head_save)
			return (1);
		if (current > tmp->num)
			return (0);
		current = tmp->num;
	}
}

void	ft_label_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp_min;
	t_list	*size_max;
	int		len;
	int		cnt;

	len = ft_stack_len(*stack);
	size_max = ft_new_stack(INT_MAX, 0, 0);
	while (--len >= 0)
	{
		tmp_min = size_max;
		tmp = *stack;
		cnt = ft_stack_len(*stack);
		while (--cnt >= 0)
		{
			if (tmp->num <= tmp_min->num && !(tmp->index))
				tmp_min = tmp;
			tmp = tmp->next;
		}
		tmp_min->index = ft_stack_len(*stack) - len;
	}
	free(size_max);
}

void	ft_operate(t_list **stack_a, t_list **stack_b)
{
	int		is_sorted;
	int		list_len;

	is_sorted = ft_check_sort(*stack_a);
	if (is_sorted != 1)
	{
		ft_label_stack(stack_a);
		list_len = ft_stack_len(*stack_a);
		if (list_len <= 3)
			ft_operate_under_three(stack_a, 'A');
		else if (list_len <= 6)
			ft_operate_under_six(stack_a, stack_b, 'A');
		else
			ft_operate_quick_sort(stack_a, stack_b);
		ft_save_command(0, 1);
	}
	ft_free_stack(stack_a);
}
