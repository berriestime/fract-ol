/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:46:15 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/25 18:02:36 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	i;

	if (!f || !s)
		return (NULL);
	result = ft_strnew(ft_strlen(s));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(s[i]);
		i++;
	}
	result[i] = s[i];
	return (result);
}
