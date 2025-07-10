/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:14:47 by yossasak          #+#    #+#             */
/*   Updated: 2024/12/02 02:03:25 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char c, const char *set)
{
	int	chr;

	chr = -1;
	while (set[++chr])
		if (set[chr] == c)
			return (1);
	return (0);
}

static int	str_start(const char *s1, const char *set)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (s1[++i])
	{
		if (!is_in_set(s1[i], set))
			break ;
		res++;
	}
	return (res);
}

static int	str_end(const char *s1, const char *set)
{
	int	i;
	int	res;

	i = ft_strlen(s1);
	res = 0;
	while (s1[--i])
	{
		if (!is_in_set(s1[i], set))
			break ;
		res++;
	}
	return (res);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = str_start(s1, set);
	end = str_end(s1, set);
	if (ft_strlen(s1) == (long unsigned int)start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) - start - end + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, ft_strlen(s1) - start - end + 1);
	return (str);
}
