/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:17:45 by dliu          #+#    #+#                 */
/*   Updated: 2024/01/15 14:27:35 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_isquote(int c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}
