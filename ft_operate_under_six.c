/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_under_six.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:05:51 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/12 10:27:22 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index_place(t_list *stack, int index)
{
	t_list	*head_save;
	t_list	*tmp;
	int		place;

	head_save = stack;
	tmp = stack;
	place = 1;
	while (tmp != NULL)
	{
		if (tmp->index == index)
			return (place);
		place ++;
		tmp = tmp->next;
		if (tmp == head_save)
			break ;
	}
	return (0);
}

void	ft_cut_to_three(t_list **main_stack, t_list **sub_stack, char which)
{
	int	min;
	int	place;

	min = ft_find_min_index(*main_stack);
	place = ft_find_index_place(*main_stack, min);
	if (place <= (ft_stack_len(*main_stack) / 2))
	{
		while ((*main_stack)->index != min)
		{
			if (which == 'A')
				ft_operate_stack(main_stack, sub_stack, RA);
			else
				ft_operate_stack(sub_stack, main_stack, RB);
		}
	}
	else
	{
		while ((*main_stack)->index != min)
		{
			if (which == 'A')
				ft_operate_stack(main_stack, sub_stack, RRA);
			else
				ft_operate_stack(sub_stack, main_stack, RRB);
		}
	}		
}

void	ft_push_remain(t_list **main_stack, t_list **sub_stack, char which)
{
	if (which == 'A')
		ft_operate_stack(main_stack, sub_stack, PA);
	else if (which == 'B')
		ft_operate_stack(sub_stack, main_stack, PB);
}

void	ft_operate_under_six(t_list **stack_a, t_list **stack_b, char which)
{
	int		len;
	t_list	**main_stack;
	t_list	**sub_stack;

	main_stack = stack_a;
	sub_stack = stack_b;
	if (which == 'B')
	{
		main_stack = stack_b;
		sub_stack = stack_a;
	}
	len = ft_stack_len(*main_stack);
	while (ft_stack_len(*main_stack) > 3)
	{
		ft_cut_to_three(main_stack, sub_stack, which);
		if (main_stack == stack_a)
			ft_operate_stack(stack_a, stack_b, PB);
		else
			ft_operate_stack(stack_a, stack_b, PA);
	}
	ft_operate_under_three(main_stack, which);
	while (ft_stack_len(*main_stack) != len)
		ft_push_remain(main_stack, sub_stack, which);
}
