/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nums.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/04 20:59:48 by dliu          #+#    #+#                 */
/*   Updated: 2023/02/01 12:01:05 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(long long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

int	ft_min(int a, int b, int min)
{
	if (a - b < min)
		return (min);
	return (a - b);
}

int	ft_smallest(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
