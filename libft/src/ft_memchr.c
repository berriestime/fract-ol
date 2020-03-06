/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:36:17 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/11 18:27:51 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*char_s;
	unsigned char		i;

	char_s = (unsigned char *)s;
	i = (unsigned char)c;
	while (n--)
	{
		if (*char_s == i)
			return ((void *)char_s);
		char_s++;
	}
	return (NULL);
}
