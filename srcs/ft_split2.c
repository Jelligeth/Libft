/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:48:52 by dliu          #+#    #+#                 */
/*   Updated: 2023/01/25 18:24:20 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_count(char *s);
static char		*extract(char **s);

char	**ft_split2(char *s)
{
	char	**strings;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = split_count(s);
	strings = ft_calloc((count + 1), sizeof(*strings));
	if (!strings)
		return (NULL);
	count = 0;
	while (*s)
	{
		while (*s && ft_strchr(" \t", *s))
			s++;
		strings[count] = extract(&s);
		count++;
	}
	strings[count] = NULL;
	return (strings);
}

static size_t	split_count(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && ft_strchr(" \t", *s))
			s++;
		if (*s && !ft_strchr(" \t\'\"", *s))
		{
			count++;
			while (*s && !ft_strchr(" \t\'\"", *s))
				s++;
		}
		if (*s == '\'' || *s == '\"')
		{
			count++;
			s = ft_strchr(s + 1, *s);
			s++;
		}
	}
	return (count);
}

static char	*extract(char **s)
{
	char	*pos;
	char	*string;

	if (**s == '\'' || **s == '\"')
	{
		pos = ft_strchr(*s + 1, **s);
		*s += 1;
		string = ft_substr(*s, 0, pos - *s);
		*s = pos + 1;
	}
	else
	{
		pos = *s;
		while (!ft_strchr(" \t\'\"", *pos))
			pos++;
		string = ft_substr(*s, 0, pos - *s);
		*s = pos;
	}
	if (!string)
		return (NULL);
	return (string);
}
