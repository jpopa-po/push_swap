/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:06:16 by jpopa-po          #+#    #+#             */
/*   Updated: 2022/07/05 20:14:56 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	if (!lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
}
// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*ptr;

// 	if (!lst)
// 		return ;
// 	while (*lst)
// 	{
// 		ptr = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = ptr;
// 	}
// }
