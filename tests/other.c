/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   other.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 16:10:56 by dliu          #+#    #+#                 */
/*   Updated: 2023/02/20 14:12:38 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	*string;

	string = ft_joinstrs(4, "this", "is", "a", "string");
	ft_putendl_fd(string, STDOUT_FILENO);
	free(string);
}
