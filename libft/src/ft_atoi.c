/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:30:37 by dmorrige          #+#    #+#             */
/*   Updated: 2019/04/22 18:56:39 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		flag;
	int		i;
	long	nbr;
	long	temp;

	flag = 1;
	nbr = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
	|| str[i] == '\r' || str[i] == '\f' || str[i] == '0')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			flag = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = nbr;
		nbr = 10 * nbr + (str[i++] - '0') * flag;
		if (temp != nbr / 10)
			return (flag < 0 ? 0 : -1);
	}
	return ((int)nbr);
}
