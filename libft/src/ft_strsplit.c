/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:47:53 by dmorrige          #+#    #+#             */
/*   Updated: 2019/05/18 19:52:21 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_c_a(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static void		*ft_free(char **a, size_t i)
{
	while (i > 0)
	{
		free(a[i]);
		i--;
	}
	free(a[i]);
	free(a);
	return (NULL);
}

static int		ft_length(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**a;

	if (!s || !(a = (char **)malloc(sizeof(char *) * (ft_c_a(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[j])
	{
		k = 0;
		while (s[j] == c)
			j++;
		a[i] = s[j] == '\0' ? NULL : (void *)1;
		if (a[i] == NULL)
			return (a);
		if (!(a[i] = ft_strnew(ft_length(&s[j], c) + 1)))
			return (ft_free(a, i));
		while (s[j] != c && s[j] != '\0')
			a[i][k++] = s[j++];
		i++;
	}
	a[i] = NULL;
	return (a);
}
