/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:58:13 by rtomiki           #+#    #+#             */
/*   Updated: 2021/07/17 15:14:28 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_for_pushswap(const char *str, t_list *head)
{
	long long	value;
	int			sign;

	value = 0;
	sign = 1;
	if (*str == '-')
	{	
		sign = -1;
		str++;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		value = 10 * value + *str - '0';
		str++;
	}
	value *= sign;
	if (*str || value > INT_MAX || value < INT_MIN)
	{
		ft_free_stack(&head);
		ft_error();
	}
	return (((int)value));
}

void	ft_check_duplicate(t_list *head, int value)
{
	t_list	*tmp;
	t_list	*head_save;

	if (head == NULL)
		return ;
	tmp = head;
	head_save = head;
	while (1)
	{
		if (tmp->num == value)
		{
			ft_free_stack(&head);
			ft_error();
		}
		tmp = tmp->next;
		if (tmp == NULL || tmp == head_save)
			break ;
	}
}

t_list	*ft_pass_argument(int argc, char **argv)
{
	int		cnt;
	int		value;
	t_list	*head;

	cnt = 0;
	head = NULL;
	while (++cnt < argc)
	{	
		value = ft_atoi_for_pushswap(argv[cnt], head);
		ft_check_duplicate(head, value);
		ft_push_back_stack(&head, value, 0, 0);
	}
	if (head == NULL)
		exit(0);
	return (head);
}
