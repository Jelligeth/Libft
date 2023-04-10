/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_validate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 16:13:54 by dliu          #+#    #+#                 */
/*   Updated: 2023/04/10 16:14:51 by dliu          ########   odam.nl         */
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
	if (!ft_isdigit(check_me[i]))
		return (0);
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

bool	ft_valid_atoi(char *check_me, int *num)
{
	int			i;
	long long	convert;

	i = 0;
	if (check_me[i] == '-' || check_me[i] == '+')
		i++;
	if (!ft_isdigit(check_me[i]))
		return (false);
	while (check_me[i])
	{
		if (!ft_isdigit(check_me[i]) || i > 10)
			return (false);
		i++;
	}
	convert = ft_atoll(check_me);
	if (convert < INT_MIN || convert > INT_MAX)
		return (false);
	*num = (int)convert;
	return (true);
}
