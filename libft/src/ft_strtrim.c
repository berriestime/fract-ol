/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:47:40 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/25 18:16:14 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (is_space(s[start]))
		start++;
	while (is_space(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	if (!(new = ft_strnew(end - start)))
		return (NULL);
	return (ft_strncpy(new, s + start, end - start));
}
