/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:14:45 by dliu          #+#    #+#                 */
/*   Updated: 2023/01/25 14:20:57 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*z;
	unsigned char	ch;

	z = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*z == ch)
			return (z);
		z++;
		n--;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cdst;
	const char	*csrc;

	if (dst != src)
	{
		cdst = (char *)dst;
		csrc = (const char *)src;
		while (n > 0)
		{
			*cdst++ = *csrc++;
			n--;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;

	if (dst != src)
	{
		cdst = (char *)dst;
		csrc = (const char *)src;
		if (csrc < cdst)
		{
			cdst += len - 1;
			csrc += len - 1;
			while (len--)
				*cdst-- = *csrc--;
		}
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*z;
	unsigned char	ch;

	i = 0;
	z = (unsigned char *)b;
	ch = (unsigned char)c;
	while (i < len)
	{
		z[i] = ch;
		i++;
	}
	return (b);
}
