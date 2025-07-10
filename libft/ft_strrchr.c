/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:14:47 by yossasak          #+#    #+#             */
/*   Updated: 2024/12/02 01:54:57 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	target;
	char	*last;

	target = (char)c;
	i = 0;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == target)
			last = (char *)&s[i];
		i++;
	}
	if (s[i] == target)
		last = (char *)&s[i];
	if (last != NULL)
		return (last);
	return (NULL);
}
