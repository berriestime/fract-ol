/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:42:56 by dmorrige          #+#    #+#             */
/*   Updated: 2019/05/18 17:27:28 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *temp2;

	temp = f(lst);
	temp2 = temp;
	if (lst == NULL || f == NULL || temp == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = f(lst)))
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
		temp = temp->next;
	}
	return (temp2);
}
