/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl_tests.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:50:18 by dliu          #+#    #+#                 */
/*   Updated: 2022/12/15 13:42:03 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		testfd = open("testfile", O_RDONLY);
	//int		testfd2 = 0;
	int		linecount;
	char	*got_line;

	printf("\n\nSTART TEST\n\n");
	linecount = 0;
	got_line = get_next_line(testfd);
	printf("Test: gotline=%s\n", got_line);
	while (got_line)
	{
		printf("___RESULT %d: GOT LINE = %s************************\n", linecount, got_line);
		free(got_line);
		got_line = get_next_line(testfd);
		linecount++;
	}
	printf("\n\nEND TEST\n\n");

	// printf("\n\nSTART TEST2\n\n");
	// linecount = 0;
	// got_line = get_next_line(testfd2);
	// while (got_line)
	// {
	// 	printf("___RESULT %d: GOT LINE = %s********\n", linecount, got_line);
	// 	free(got_line);
	// 	got_line = get_next_line(testfd2);
	// 	linecount++;
	// }
	// printf("\n\nEND TEST2\n\n");
	close(testfd);
}
