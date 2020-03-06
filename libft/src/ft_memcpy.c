/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:35:49 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/11 17:55:57 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (dest == src)
		return (dest);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	while (n--)
	{
		*char_dest++ = *char_src++;
	}
	return (dest);
}
