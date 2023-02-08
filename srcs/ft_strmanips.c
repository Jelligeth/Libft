/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmanips.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 11:20:15 by dliu          #+#    #+#                 */
/*   Updated: 2023/01/25 17:45:00 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*string;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		string = ft_calloc(len + 1, sizeof(*string));
		if (string != NULL)
		{
			while (s[i] != '\0')
			{
				string[i] = f(i, s[i]);
				i++;
			}
			string[i] = '\0';
			return (string);
		}
	}
	return (NULL);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

char	*ft_strrev(char *string)
{
	char	hold;
	size_t	start;
	size_t	end;
	size_t	len;

	len = ft_strlen(string);
	if (string && len > 1)
	{
		start = 0;
		end = len - 1;
		while (start < end)
		{
			hold = string[end];
			string[end] = string[start];
			string[start] = hold;
			start++;
			end--;
		}
		string[len] = '\0';
	}
	return (string);
}
