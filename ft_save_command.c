/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:56:39 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/13 21:26:36 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_command_merge_2(int first, int second, t_list **tmp)
{
	t_list	*tmp_pop;

	if ((first == RA && second == RB) || (first == RB && second == RA))
	{
		(*tmp)->num = RR;
		(*tmp) = (*tmp)->next;
		tmp_pop = ft_pop_stack(tmp);
		ft_free_stack(&tmp_pop);
		return (RR);
	}
	if ((first == RRA && second == RRB) || (first == RRB && second == RRA))
	{
		(*tmp)->num = RRR;
		(*tmp) = (*tmp)->next;
		tmp_pop = ft_pop_stack(tmp);
		ft_free_stack(&tmp_pop);
		return (RRR);
	}
	return (0);
}

int	ft_command_merge(int first, int second, t_list **tmp)
{
	t_list	*tmp_pop;

	if ((first == SA && second == SB) || (first == SB && second == SA))
	{
		(*tmp)->num = SS;
		(*tmp) = (*tmp)->next;
		tmp_pop = ft_pop_stack(tmp);
		ft_free_stack(&tmp_pop);
		return (SS);
	}
	if ((first == PA && second == PB) || (first == PB && second == PA))
	{
		tmp_pop = ft_pop_stack(tmp);
		ft_free_stack(&tmp_pop);
		tmp_pop = ft_pop_stack(tmp);
		ft_free_stack(&tmp_pop);
		return (NOTHING);
	}
	if (ft_command_merge_2(first, second, tmp))
		return (1);
	return (0);
}

void	ft_merge_command(t_list **stack)
{
	t_list	*head;
	int		flag;
	int		flag_merge;

	head = *stack;
	flag = 1;
	if (head == NULL || head->next == NULL)
		return ;
	while (flag)
	{
		flag_merge = 1;
		head = head->next;
		while (head->num)
		{
			if (ft_command_merge(head->num, head->next->num, &head))
			{
				flag_merge = 0;
				continue ;
			}
			head = head->next;
		}
		if (flag_merge)
			flag = 0;
	}
}

t_list	*ft_save_command_to_chain(int mem[])
{
	t_list	*tmp;
	int		cnt;

	cnt = 0;
	tmp = NULL;
	ft_push_back_stack(&tmp, 0, 0, 0);
	while (mem[cnt])
	{
		ft_push_back_stack(&tmp, mem[cnt], 0, 0);
		cnt ++;
	}
	ft_merge_command(&tmp);
	return (tmp);
}

void	ft_save_command(int command, int output)
{
	static int	mem[100000000];
	int			i;
	t_list		*command_list;

	i = 0;
	command_list = NULL;
	if (output == 0)
	{
		while (mem[i])
			i++;
		mem[i] = command;
	}
	else if (output == 1)
	{
		command_list = ft_save_command_to_chain(&mem[0]);
		ft_operate_print(&command_list);
	}
	ft_free_stack(&command_list);
}
