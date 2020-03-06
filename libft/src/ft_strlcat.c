/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:36:50 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/22 14:07:04 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*a;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	a = (char *)src;
	while (a[j] && (i + j + 1) < size)
	{
		dst[i + j] = a[j];
		j++;
	}
	if (i < size)
		dst[i + j] = 0;
	return (i + ft_strlen(src));
}
