/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:33:46 by cmarcu            #+#    #+#             */
/*   Updated: 2022/04/24 14:44:53 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// sa | sb | ss -> Intercambiar los primeros 2 elementos en la parte
// superior de la pila x. No hace nada si sólo hay uno o ningún elementos.

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
