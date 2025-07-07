/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:50:03 by yossasak          #+#    #+#             */
/*   Updated: 2025/07/07 15:46:35 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_freeall(char **res, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (1);
}

static size_t	ft_split_arraycount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*make_array(const char *s, size_t len, char **res, size_t n)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		ft_freeall(res, n);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	splited_arraysize;
	size_t	i;
	char	*stmp;

	splited_arraysize = ft_split_arraycount(s, c);
	res = (char **)ft_calloc(splited_arraysize + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s && i < splited_arraysize)
	{
		while (*s && *s == c)
			s++;
		stmp = (char *)s;
		while (*s && *s != c)
			s++;
		res[i] = make_array(stmp, s - stmp, res, i);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}
