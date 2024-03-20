/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_strarray.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 17:08:51 by dliu          #+#    #+#                 */
/*   Updated: 2024/03/20 14:03:43 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Prints a string array to fd
void	ft_put_strarray_fd(char **strarray, int fd)
{
	int	i;

	if (!strarray)
		return ;
	i = 0;
	while (strarray[i])
	{
		ft_putstr_fd(strarray[i], fd);
		i++;
	}
}
