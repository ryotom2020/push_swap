/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:25:51 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/13 20:05:20 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_command(int i)
{
	if (i == SA)
		write(1, "sa\n", 3);
	if (i == SB)
		write(1, "sb\n", 3);
	if (i == SS)
		write(1, "ss\n", 3);
	if (i == PA)
		write(1, "pa\n", 3);
	if (i == PB)
		write(1, "pb\n", 3);
	if (i == RA)
		write(1, "ra\n", 3);
	if (i == RB)
		write(1, "rb\n", 3);
	if (i == RR)
		write(1, "rr\n", 3);
	if (i == RRA)
		write(1, "rra\n", 4);
	if (i == RRB)
		write(1, "rrb\n", 4);
	if (i == RRR)
		write(1, "rrr\n", 4);
	if (i == NOTHING)
		return ;
}

void	ft_operate_print(t_list **command)
{
	t_list	*tmp;

	tmp = *command;
	tmp = tmp->next;
	while (tmp->num)
	{
		ft_print_command(tmp->num);
		tmp = tmp->next;
	}
}
