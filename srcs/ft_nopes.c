/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nopes.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:57:09 by dliu          #+#    #+#                 */
/*   Updated: 2023/11/07 15:54:26 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Prints an error message to STDERR_FILENO and exits with EXIT_FAILURE.
void	ft_error(char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

//Prints errmsg to STDERR_FILENO and exits with errcode.
void	ft_errexit(char *errmsg, int errcode)
{
	if (errmsg)
		ft_putendl_fd(errmsg, STDERR_FILENO);
	exit(errcode);
}

/**
 * Prints an error message based on inputs. 
 * NULL inputs will be skipped.
*/
void	ft_perror(const char *prog, const char *func, const char *msg)
{
	if (prog)
	{
		ft_putstr_fd(prog, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (func)
	{
		ft_putstr_fd(func, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
}
