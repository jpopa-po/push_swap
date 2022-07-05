/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:38:43 by jpopa-po          #+#    #+#             */
/*   Updated: 2022/05/16 13:39:18 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// sa | sb | ss -> swapping the first 2 elements
// top of each stack, id does nothing if is only 1 or 0 elements

int	swap_rule(t_swap *swap, t_list *stack)
{
	int	aux;

	if (stack && stack->next)
	{
		aux = stack->content;
		stack->content = stack->next->content;
		stack->next->content = aux;
		swap->moves += 1;
		return (1);
	}
	return (0);
}

int	sa(t_swap *swap)
{
	if (swap_rule(swap, swap->stack_a))
		return (1);
	return (0);
}

int	sb(t_swap *swap)
{
	if (swap_rule(swap, swap->stack_b))
		return (1);
	return (0);
}

int	ss(t_swap *swap)
{
	int	control;

	control = 0;
	if (swap_rule(swap, swap->stack_a))
		control++;
	if (swap_rule(swap, swap->stack_b))
		control++;
	if (control == 2)
		return (1);
	return (0);
}
