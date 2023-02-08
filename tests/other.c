/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   other.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 16:10:56 by dliu          #+#    #+#                 */
/*   Updated: 2023/02/07 15:05:50 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main(void)
{
	ft_putnbr_fd(-1, STDOUT_FILENO);
	ft_putnbr_fd(-0, STDOUT_FILENO);
	ft_putnbr_fd(1001001, STDOUT_FILENO);
}
