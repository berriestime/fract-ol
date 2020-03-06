/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:37:09 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/25 16:33:01 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	if (needle == haystack || needle[0] == '\0')
		return (char *)(haystack);
	while (haystack[j])
	{
		if (haystack[j] == needle[i])
		{
			n = j;
			while (needle[i] == haystack[n])
			{
				i++;
				n++;
				if (i == ft_strlen(needle))
					return (char *)(haystack + n - ft_strlen(needle));
			}
		}
		i = 0;
		j++;
	}
	return (NULL);
}
