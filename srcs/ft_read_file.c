/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl> 		          +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 19:37:29 by dliu          #+#    #+#                 */
/*   Updated: 2024/03/15 20:41:44 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Reads the entire file at @param filename and returns it as a string.
*/
char	*ft_read_file(char *filename)
{
	int		fd;
	int		rcount;
	char	buffer[BUFFER_SIZE + 1];
	char	*maptxt;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		return (NULL);
	}
	rcount = read(fd, buffer, BUFFER_SIZE);
	buffer[rcount] = '\0';
	maptxt = ft_strdup(buffer);
	rcount = read(fd, buffer, BUFFER_SIZE);
	while (rcount && maptxt)
	{
		buffer[rcount] = '\0';
		tmp = ft_strjoin(maptxt, buffer);
		free(maptxt);
		maptxt = tmp;
		rcount = read(fd, buffer, BUFFER_SIZE);
	}
	return (maptxt);
}
