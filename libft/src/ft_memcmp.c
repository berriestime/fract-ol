/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:36:23 by dmorrige          #+#    #+#             */
/*   Updated: 2019/05/17 12:03:15 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *mp1, const void *mp2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)mp1;
	str2 = (unsigned char *)mp2;
	i = 0;
	while (n--)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (0);
}
