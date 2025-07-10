/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:14:47 by yossasak          #+#    #+#             */
/*   Updated: 2024/12/01 23:10:59 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	target;

	target = (char)c;
	str = (char *)s;
	while (*str != target)
	{
		if (!(*str))
			return (NULL);
		str++;
	}
	return (str);
}

// #include "<stdio.h>"

// int main(void)
// {
// 	char	*s;

// 	s = "libfttest";
// 	printf("a %d\n", 'l' + 256);
// 	printf("\nft_strchr %s\n", ft_strchr(s, 'l' + 256));
// 	printf("\nstrchr %s\n", strchr(s, 'l' + 256));
// 	return (0);
// }
