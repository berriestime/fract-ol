/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:36:38 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/14 06:24:51 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)ch)
		i++;
	if (str[i] == (char)ch)
		return (char *)(str + i);
	return (NULL);
}
