/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:23:23 by yossasak          #+#    #+#             */
/*   Updated: 2025/03/28 02:26:25 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_getc(int fd)
{
	static unsigned char	buf[BUFFER_SIZE];
	static unsigned char	*bufp = buf;
	static int				n;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
		{
			n = 0;
			return (READ_ERROR);
		}
		if (n == 0)
			return (EOF);
		bufp = buf;
	}
	if (--n >= 0)
		return (*bufp++);
	return (EOF);
}

static char	*extract_line(char *str, char c)
{
	char	temp[2];
	char	*new_str;

	temp[0] = c;
	temp[1] = '\0';
	if (str == NULL)
		new_str = ft_strjoin("", temp);
	else
		new_str = ft_strjoin(str, temp);
	return (new_str);
}

static char	*read_line(int fd)
{
	char	*result;
	char	c;
	char	*new_line;

	result = NULL;
	c = ft_getc(fd);
	while (c != EOF && c != READ_ERROR)
	{
		new_line = extract_line(result, c);
		free(result);
		if (!new_line)
			return (NULL);
		result = new_line;
		if (c == '\n')
			break ;
		c = ft_getc(fd);
	}
	if (c == READ_ERROR)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_line(fd));
}
