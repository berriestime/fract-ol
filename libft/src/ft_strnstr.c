/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:37:04 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/25 17:30:22 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = -1;
	if (lit == big || lit[0] == '\0')
		return (char *)(big);
	if (big[0] == '\0')
		return (NULL);
	while (big[++j] != '\0' && j < len)
	{
		if (big[j] == lit[i = 0])
		{
			k = j + 1;
			while (lit[++i] && k < len)
			{
				if (lit[i] != big[k++])
					break ;
			}
			if (i == ft_strlen(lit))
				return (char *)(&big[j]);
		}
	}
	return (NULL);
}
