/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:48:07 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/24 11:38:52 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		digit_count(unsigned int nb)
{
	unsigned int	count;

	count = 1;
	while (nb /= 10)
		count++;
	return (count);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	n_cpy;
	unsigned int	i;
	unsigned int	len;

	if (n < 0)
		n_cpy = (unsigned int)(n * -1);
	else
		n_cpy = (unsigned int)n;
	len = (unsigned int)digit_count(n_cpy);
	i = 0;
	if (!(str = ft_strnew(len + (n < 0 ? 1 : 0))))
		return (0);
	if (n < 0 && (str[i] = '-'))
		len++;
	i = len - 1;
	while (n_cpy >= 10)
	{
		str[i--] = (char)(n_cpy % 10 + '0');
		n_cpy /= 10;
	}
	str[i] = (char)(n_cpy % 10 + '0');
	str[len] = '\0';
	return (str);
}
