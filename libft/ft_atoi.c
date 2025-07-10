/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:14:47 by yossasak          #+#    #+#             */
/*   Updated: 2024/12/02 01:30:17 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atoi(const char *nptr)
{
	long	n;
	int		plus;
	size_t	i;

	n = 0;
	plus = 1;
	i = 0;
	while (ft_isblank(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			plus *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (plus == 1 && (LONG_MAX / 10 <= n && '8' <= nptr[i]))
			return ((int)LONG_MAX);
		if (plus == -1 && (LONG_MAX / 10 <= n && '9' <= nptr[i]))
			return ((int)LONG_MIN);
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(plus * n));
}
