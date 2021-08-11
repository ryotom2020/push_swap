/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:49:50 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/12 11:40:31 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_new_stack(int num, int index, int class)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		ft_error();
	new->num = num;
	new->index = index;
	new->class = class;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_list	*ft_pop_stack(t_list **stack)
{
	t_list	*head;
	t_list	*res;

	head = *stack;
	if (head == NULL)
		return (NULL);
	res = head;
	if (head->prev == NULL)
		*stack = NULL;
	else if (head->prev == head->next)
	{
		head->next->prev = NULL;
		head->next->next = NULL;
		*stack = head->next;
	}
	else
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		*stack = head->next;
	}
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	ft_push_back_stack(t_list **head, int num, int index, int class)
{
	t_list	*add;

	add = ft_new_stack(num, index, class);
	if (*head == NULL)
	{
		*head = add;
		return ;
	}
	if ((*head)->prev == NULL)
	{
		(*head)->next = add;
		(*head)->prev = add;
		add->next = (*head);
		add->prev = (*head);
	}
	else
	{
		(*head)->prev->next = add;
		add->prev = (*head)->prev;
		add->next = (*head);
		(*head)->prev = add;
	}
}

void	ft_push_front_stack(t_list **head, int num, int index, int class)
{
	ft_push_back_stack(head, num, index, class);
	if ((*head)->prev == NULL)
		return ;
	*head = (*head)->prev;
}

int	ft_stack_len(t_list *head)
{
	t_list	*head_save;
	t_list	*tmp;
	int		cnt;

	head_save = head;
	tmp = head;
	cnt = 0;
	while (tmp != NULL)
	{
		cnt++;
		tmp = tmp->next;
		if (tmp == head_save)
			break ;
	}
	return (cnt);
}
