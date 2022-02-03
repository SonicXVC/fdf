/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:18:42 by ameteori          #+#    #+#             */
/*   Updated: 2021/10/22 14:46:26 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*dst;
	t_list	*lstcpy;

	if (!lst || !f)
		return (NULL);
	dst = ft_lstnew(f(lst -> content));
	if (!dst)
	{
		return (NULL);
	}
	lstcpy = lst -> next;
	while (lstcpy)
	{
		tmp = ft_lstnew(f(lstcpy -> content));
		if (!tmp)
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		ft_lstadd_back(&dst, tmp);
		lstcpy = lstcpy -> next;
	}
	return (dst);
}
