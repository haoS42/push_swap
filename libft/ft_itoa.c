/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:14:47 by yossasak          #+#    #+#             */
/*   Updated: 2024/12/02 02:08:40 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	i;

	i = 1;
	n = n / 10;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			digits;
	char		*res;
	long int	num;

	num = n;
	digits = get_len(num);
	if (n < 0)
	{
		digits++;
		num *= -1;
	}
	res = (char *)malloc(sizeof(char) * (digits + 1));
	if (!res)
		return (NULL);
	res[digits] = 0;
	while (digits--)
	{
		res[digits] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
