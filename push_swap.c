/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:39:03 by jpopa-po          #+#    #+#             */
/*   Updated: 2022/07/05 20:31:04 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/libft.h"

void	push_swap_fill(int argc, char **argv, t_swap *swap)
{
	int		i;
	int		j;
	int		num;
	char	**temp;

	j = 1;
	while (j < argc)
	{
		temp = ft_split(argv[j], ' ');
		i = 0;
		while (temp[i])
		{
			check_for_letters(i, temp);
			num = ft_atoi_tunned(temp[i]);
			swap->repeated = num;
			check_repeated(swap, swap->stack_a);
			ft_lstadd_back(&swap->stack_a, ft_lstnew(num));
			i++;
		}
		free_split(temp);
		j++;
	}
	swap->lst_length = ft_lstsize(swap->stack_a);
}

int	max_position(t_list *stack)
{
	t_list	*aux;
	int		max;
	int		pos;
	int		i;

	aux = stack;
	max = aux->content;
	pos = 0;
	i = 0;
	while (aux)
	{
		if (max < aux->content)
		{
			max = aux->content;
			pos = i;
		}
		i++;
		aux = aux->next;
	}
	return (pos);
}

void	push_back(t_swap *swap)
{
	int	position;
	int	i;
	int	b_length;

	b_length = ft_lstsize(swap->stack_b);
	i = 0;
	while (i < b_length)
	{
		position = max_position(swap->stack_b);
		get_to_top_b(position, swap);
		do_rule(swap, "pa");
		i++;
	}
}

void	chunk_algorithm(t_swap *swap)
{
	int	*stack_copy;
	int	*chunk;
	int	position;
	int	i;
	int	j;

	j = -1;
	while (++j < number_of_chunks(swap->lst_length))
	{
		stack_copy = (int *)malloc(sizeof(int) * swap->lst_length);
		chunk = (int *)malloc(sizeof(int) * swap->chunk_length);
		copy_stack_to_array(swap->stack_a, stack_copy);
		fill_chunk(swap, chunk, stack_copy);
		i = -1;
		while (++i < swap->chunk_length)
		{
			copy_stack_to_array(swap->stack_a, stack_copy);
			position = retrieve_position(swap, chunk, stack_copy);
			get_to_top(position, swap);
			do_rule(swap, "pb");
		}
		free(stack_copy);
		free(chunk);
	}
	push_back(swap);
}

int	main(int argc, char **argv)
{
	t_swap	ps;

	if (argc < 2)
		return (0);
	push_swap_fill(argc, argv, &ps);
	if (check_sorted(ps.stack_a))
		exit(1);
	push_swap_sorter(&ps);
	ft_lstclear(&ps.stack_a);
	ft_lstclear(&ps.stack_b);
}
