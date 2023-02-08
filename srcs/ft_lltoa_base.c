/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoa_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 12:21:22 by dliu          #+#    #+#                 */
/*   Updated: 2022/12/06 18:29:58 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lltoa_extend(long long num, char *buffer, int len, int base)
{
	int	rem;

	rem = 0;
	while (len >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buffer[len] = 'a' + (rem - 10);
		else
			buffer[len] = '0' + rem;
		num = num / base;
		len--;
	}
}

char	*ft_lltoa_base(long long n, int base)
{
	unsigned long long	num;
	char				*buffer;
	int					len;

	len = ft_numlen(n, base);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	buffer[len] = '\0';
	len--;
	num = n;
	if (n < 0 && base == 10)
	{
		buffer[0] = '-';
		num = -n;
	}
	lltoa_extend(num, buffer, len, base);
	return (buffer);
}
