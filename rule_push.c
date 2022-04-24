/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:15:55 by cmarcu            #+#    #+#             */
/*   Updated: 2022/04/24 14:44:42 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// pa | pb | pp -> Toma el primer elemento en la parte superior de a ó b
// y ponerlo en la parte superior de a ó b. No hace nada si a ó b está vacío.

int	pb(t_swap **head)
{
	t_list	*tmp;
	t_list	*to;
	t_list	*from;

	to = (*head)->stack_b;
	from = (*head)->stack_a;
	if (!from)
		return (0);
	tmp = from;
	from = from->next;
	(*head)->stack_a = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		(*head)->stack_b = to;
	}
	else
	{
		tmp->next = to;
		(*head)->stack_b = tmp;
	}
	(*head)->moves += 1;
	return (1);
}

int	pa(t_swap **head)
{
	t_list	*tmp;
	t_list	*to;
	t_list	*from;

	to = (*head)->stack_a;
	from = (*head)->stack_b;
	if (!from)
		return (0);
	tmp = from;
	from = from->next;
	(*head)->stack_b = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		(*head)->stack_a = to;
	}
	else
	{
		tmp->next = to;
		(*head)->stack_a = tmp;
	}
	(*head)->moves += 1;
	return (1);
}

void	repeat_rule_push(int n, char *str, t_swap **swap)
{
	int	i;

	i = 0;
	if (!(ft_strncmp(str, "pa", 2)))
	{
		while (i < n)
		{
			do_rule(*swap, "pa");
			i++;
		}
	}
	else if (!(ft_strncmp(str, "pb", 2)))
	{
		while (i < n)
		{
			do_rule(*swap, "pa");
			i++;
		}
	}
}
