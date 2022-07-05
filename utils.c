/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:38:31 by jpopa-po          #+#    #+#             */
/*   Updated: 2022/05/16 13:39:26 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	number_of_chunks(int lst_length)
{
	return ((lst_length + 233.333333) / 66.666666);
}

int	ft_lstsize(t_list *lst)
{
	int	result;

	result = 0;
	while (lst)
	{
		lst = lst->next;
		result++;
	}
	return (result);
}

void	free_split(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	if (temp)
		free(temp);
}

int	ft_atoi_tunned(const char *nptr)
{
	long	n;
	long	i;
	long	sign;

	n = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45)
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == 43 || nptr[i] == 45)
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]) == 1)
	{
		n = n * 10 + (nptr[i++] - 48);
		if ((n * sign) > 2147483647)
			print_error();
		if ((n * sign) < -2147483648)
			print_error();
	}
	return (sign * n);
}
