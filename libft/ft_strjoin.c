/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:14:47 by yossasak          #+#    #+#             */
/*   Updated: 2024/12/02 01:30:53 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size + 1);
	return (str);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*ptr;

// 	i = 0;
// 	j = -1;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!ptr)
// 		return (NULL);
// 	while (s1[j++])
// 		ptr[i++] = s1[j];
// 	j = -1;
// 	while (s2[j++])
// 		ptr[i++] = s2[j];
// 	ptr[i] = 0;
// 	return (ptr);
// }
