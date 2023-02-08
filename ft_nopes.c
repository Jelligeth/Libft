/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nopes.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:57:09 by dliu          #+#    #+#                 */
/*   Updated: 2023/02/07 15:09:46 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_perror(char *progname, char *err, char *messsage)
{
	if (progname)
	{
		ft_putstr_fd(progname, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (err)
	{
		ft_putstr_fd(err, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (messsage)
		ft_putendl_fd(messsage, STDERR_FILENO);
}

void	ft_pdebug(int c)
{
	ft_printf("%d:DEBUGGING\n", c);
}
