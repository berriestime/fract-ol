/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:35:23 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/11 17:54:59 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;
	unsigned char	sum;
	size_t			i;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	sum = (unsigned char)c;
	i = 0;
	while (n--)
	{
		i++;
		if (*char_src == sum)
		{
			*char_dest++ = *char_src++;
			return (dest += i);
		}
		else
			*char_dest++ = *char_src++;
	}
	return (NULL);
}
