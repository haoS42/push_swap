/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:14:47 by yossasak          #+#    #+#             */
/*   Updated: 2024/12/02 01:22:59 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (c == sep)
	{
		return (1);
	}
	return (0);
}

static int	count_words(const char *str, char c)
{
	size_t	word_count;
	int		inside_word;
	size_t	i;

	word_count = 0;
	inside_word = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], c))
		{
			inside_word = 0;
		}
		else if (!inside_word)
		{
			inside_word = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

static char	*allocate_and_copy_word(const char *str, char c)
{
	size_t	len;
	char	*word;
	size_t	i;

	len = 0;
	i = 0;
	while (str[len] && !is_sep(str[len], c))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
		word[i++] = *str++;
	word[len] = '\0';
	return (word);
}

static void	free_split(char **result, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(result[j]);
		j++;
	}
	free(result);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	result = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	i = 0;
	j = 0;
	if (!result)
		return (NULL);
	while (str[j])
	{
		if (!is_sep(str[j], c))
		{
			result[i] = allocate_and_copy_word(&str[j], c);
			if (result[i] == NULL)
				return (free_split(result, i), NULL);
			while (str[j] && !is_sep(str[j], c))
				j++;
			i++;
		}
		else
			j++;
	}
	result[i] = NULL;
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Hello, Gorilla! This is C programming.";
// 	char	**result;
// 	int		i;
// 	char	charset[] = "g ,!";

// 	result = ft_split(str, charset);
// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("Word %d: %s\n", i + 1, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
