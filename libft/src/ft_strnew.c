/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:43:41 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/25 16:50:37 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mems;

	if (size + 1 == 0)
		return (NULL);
	if (!(mems = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(mems, size + 1);
	return (mems);
}
