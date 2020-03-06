/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:47:09 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/24 21:25:52 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s || !(new = ft_strnew(len)))
		return (0);
	i = 0;
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}
