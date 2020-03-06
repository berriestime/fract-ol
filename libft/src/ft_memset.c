/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:36:33 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/18 04:06:42 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		((unsigned char *)memptr)[i] = (unsigned char)val;
		i++;
	}
	return (memptr);
}
