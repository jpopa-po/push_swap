/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:38:52 by jpopa-po          #+#    #+#             */
/*   Updated: 2022/05/16 13:39:16 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	rx(t_list **head, t_swap *swap)
{
	t_list	*aux;
	t_list	*first;
	t_list	*last;

	aux = *head;
	if (!(aux && aux->next))
		return (0);
	first = aux;
	aux = aux->next;
	last = aux;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = aux;
	swap->moves += 1;
	return (1);
}

int	rr(t_list **head_a, t_list **head_b, t_swap *swap)
{
	int	control;

	control = 0;
	control = rx(head_a, swap);
	control += rx(head_b, swap);
	if (control == 2)
		return (1);
	return (0);
}

int	rrx(t_list **head, t_swap *swap)
{
	t_list	*aux;
	t_list	*previous;
	t_list	*last;

	aux = *head;
	if (!(aux && aux->next))
		return (0);
	last = aux;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	last->next = aux;
	previous->next = NULL;
	*head = last;
	swap->moves += 1;
	return (1);
}

int	rrr(t_list **head_a, t_list **head_b, t_swap *swap)
{
	int	control;

	control = 0;
	if (rrx(head_a, swap))
		control++;
	if (rrx(head_b, swap))
		control++;
	if (control == 2)
		return (1);
	return (0);
}

void	repeat_rule_rotate(int n, char *str, t_swap *swap)
{
	int	i;

	i = -1;
	if (!(ft_strncmp(str, "ra", 2)))
	{
		while (++i < n)
			do_rule(swap, "ra");
	}
	else if (!(ft_strncmp(str, "rra", 3)))
	{
		while (++i < n)
			do_rule(swap, "rra");
	}
	else if (!(ft_strncmp(str, "rb", 2)))
	{
		while (++i < n)
			do_rule(swap, "rb");
	}
	else if (!(ft_strncmp(str, "rrb", 3)))
	{
		while (++i < n)
			do_rule(swap, "rrb");
	}
}
