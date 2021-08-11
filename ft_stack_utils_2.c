/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:49:50 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/13 21:26:56 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max_index(t_list *stack)
{
	t_list	*head_save;
	t_list	*tmp;
	int		max;

	max = 0;
	head_save = stack;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
		if (tmp == head_save)
			break ;
	}
	return (max);
}

int	ft_find_min_index(t_list *stack)
{
	t_list	*head_save;
	t_list	*tmp;
	int		min;

	min = INT_MAX;
	head_save = stack;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index <= min)
			min = tmp->index;
		tmp = tmp->next;
		if (tmp == head_save)
			break ;
	}
	return (min);
}

void	ft_free_stack(t_list **target)
{
	t_list	*head;
	t_list	*tmp;

	head = *target;
	if (head == NULL)
		return ;
	while (1)
	{
		tmp = head->next;
		free(head);
		head = tmp;
		if (head == *target || head == NULL)
			break ;
	}
}
