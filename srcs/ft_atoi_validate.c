/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_validate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 16:13:54 by dliu          #+#    #+#                 */
/*   Updated: 2023/03/22 17:20:35 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_validate(char *check_me, int *num)
{
	int			i;
	long long	convert;

	i = 0;
	if (check_me[i] == '-' || check_me[i] == '+')
		i++;
	while (check_me[i])
	{
		if (!ft_isdigit(check_me[i]) || i > 10)
			return (0);
		i++;
	}
	convert = ft_atoll(check_me);
	if (convert < INT_MIN || convert > INT_MAX)
		return (0);
	*num = (int)convert;
	return (1);
}
