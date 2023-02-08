/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfinds.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 17:10:10 by dliu          #+#    #+#                 */
/*   Updated: 2023/01/25 17:05:19 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	return (ft_memchr(s, c, len + 1));
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			end;

	end = ft_strlen(s) + 1;
	ch = (unsigned char)c;
	s += end - 1;
	while (end-- > 0)
	{
		if (*s == ch)
			return ((char *) s);
		s--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char*needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((s1 && !s2) || (s2 && !s1))
			return (-1);
		if (s1[i] != s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
