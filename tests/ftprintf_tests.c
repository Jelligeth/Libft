/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftprintf_tests.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 13:42:48 by dliu          #+#    #+#                 */
/*   Updated: 2023/02/08 12:47:23 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

void	test_print_chars(void)
{
	int real;
	int mock;

	printf("\n***TEST PRINT CHARS***\n");
	real = printf("real: %%\n");
	mock = ft_printf("mock: %%\n");
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: %c\n", 'a');
	mock = ft_printf("mock: %c\n", 'a');
	printf("real returned: %i\nmock returned: %i", real, mock);
	printf("\n*********END*********\n");
}

void	test_print_string(void)
{
	int real;
	int mock;
	char fakestring[1];

	printf("\n***TEST PRINT STRINGS***\n");
	real = printf("real: %s continued\n", "_test STRING 123");
	mock = ft_printf("mock: %s continued\n", "_test STRING 123");
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: %s\n", fakestring);
	mock = ft_printf("mock: %s\n", fakestring);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: NULL %s\n", NULL);
	mock = ft_printf("mock: NULL %s\n", NULL);
	printf("real returned: %i\nmock returned: %i", real, mock);
	printf("\n*********END*********\n");
}

void	test_print_ints(void)
{
	int	real;
	int	mock;
	int	i = -42;
	unsigned int u = -1;

	printf("\n***TEST PRINT NUMBERS***\n");
	real = printf("real: %i\n", i);
	mock = ft_printf("mock: %i\n", i);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: %i\n", -2147483647);
	mock = ft_printf("mock: %i\n", -2147483647);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: %u\n", u);
	mock = ft_printf("mock: %u\n", u);
	printf("real returned: %i\nmock returned: %i", real, mock);
	printf("\n*********END*********\n");
}

void	test_print_hexes(void)
{
	int	real;
	int	mock;
	
	int	x;
	int	X;
	void *p;

	x = 42;
	X = 42;
	p = &x;
	printf("\n***TEST PRINT hexes***\n");
	real = printf("real: %x\n", x);
	mock = ft_printf("mock: %x\n", x);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: %X\n", X);
	mock = ft_printf("mock: %X\n", X);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: %p\n", p);
	mock = ft_printf("mock: %p\n", p);
	printf("real returned: %i\nmock returned: %i", real, mock);
	printf("\n*********END*********\n");
}

void	test_print_edge(void)
{
	int	real;
	int	mock;

	printf("\n***TEST PRINT edgecases***\n");
	real = printf("real: \x01\x02\a\v\b\f\r\n");
	mock = ft_printf("mock: \x01\x02\a\v\b\f\r\n");
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: %u\n", -1);
	mock = ft_printf("mock: %u\n", -1);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: %d beans on toast %\n");
	mock = ft_printf("mock: %d beans on toast %\n");
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	real = printf("real: %%");
	mock = ft_printf("mock: %%");
	printf("real returned: %i\nmock returned: %i\n\n ", real, mock);
	printf("\n*********END*********\n");
}

void	test_print_dash_ints(void)
{
	int	real;
	int	mock;
	int	i;

	i = 0;
	printf("\n***TEST PRINT INTS bonus***\n\n");
	i++;
	real = printf("real%i: dash %+ dend\n", i, 2147483647);
	mock = ft_printf("mock%i: dash %+ dend\n", i, 2147483647);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: dash neg unsigned %-uend\n", i, -2);
	mock = ft_printf("mock%i: dash neg unsigned %-uend\n", i, -2);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: dash pad space %- 3dend\n", i, 1);
	mock = ft_printf("mock%i: dash pad space %- 3dend\n", i, 1);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: dash multi 1: %-5d 2: %-5dend\n", i, 83, 0123);
	mock = ft_printf("mock%i: dash multi 1: %-5d 2: %-5dend\n", i, 83, 0123);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: dash minmax %-5dend\n", i, 0);
	mock = ft_printf("mock%i: dash minmax %-5dend\n", i, 0);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: mixed flags %-5dend\n", i, INT_MAX);
	mock = ft_printf("mock%i: mixed flags %-5dend\n", i, INT_MAX);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);

	printf("\n*********END*********\n");
}

void	test_print_dash_chars(void)
{
	int	real;
	int	mock;
	int	i;

	i = 0;
	printf("\n***TEST PRINT CHARS bonus***\n\n");
	i++;
	real = printf("real%i: pad char -%1c- -%2c- -%-3c- end\n", i, '1', '1', '1');
	mock = ft_printf("mock%i: pad char -%1c- -%2c- -%-3c- end\n", i, '1', '1', '1');
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: null chars -%c- -%1c- -%3c- -%-3c- end\n", i, 0, 0, 0, 0);
	mock = ft_printf("mock%i: null chars -%c- -%1c- -%3c- -%-3c- end\n", i, 0, 0, 0, 0);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: pad empty string -%3s- end\n", i, "");
	mock = ft_printf("mock%i: pad empty string -%3s- end\n", i, "");
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: pad null string %s -%3s- -%-3s- end\n", i, NULL, NULL, NULL);
	mock = ft_printf("mock%i: pad null string %s -%3s- -%-3s- end\n", i, NULL, NULL, NULL);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: pad string -%1s- -%-1s- -%4s- -%-4s- \n", i, " 1 ", " 1 ", " 1 ", " 1 ");
	mock = ft_printf("mock%i: pad string -%1s- -%-1s- -%4s- -%-4s- \n", i, " 1 ", " 1 ", " 1 ", " 1 ");
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	printf("\n*********END*********\n");
}

void	test_print_precision(void)
{
	int	real;
	int	mock;
	int	i;

	i = 0;
	printf("\n***TEST PRINT PRECISION bonus***\n\n");
	i++;
	real = printf("real%i: precision zero string %.send\n", i, "111");
	mock = ft_printf("mock%i: precision zero string %.send\n", i, "111");
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: precision zero char %.cend\n", i, 'a');
	mock = ft_printf("mock%i: precision zero char %.cend\n", i, 'a');
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: precision zero string null %.send\n", i, NULL);
	mock = ft_printf("mock%i: precision zero string null %.send\n", i, NULL);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
		i++;
	real = printf("real%i: mixed %19.42send\n", i, NULL);
	mock = ft_printf("mock%i: mixed %19.42send\n", i, NULL);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: precision zero buff string %7.5send\n", i, "Bombastic");
	mock = ft_printf("mock%i: precision zero buff string %7.5send\n", i, "Bombastic");
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: precision %+dend\n", i, LONG_MIN);
	mock = ft_printf("mock%i: precision %+dend\n", i, LONG_MIN);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	printf("\n*********END*********\n");
}

void	test_print_extras(void)
{
	int	real;
	int	mock;
	int	i;

	i = 0;
	printf("\n***TEST PRINT EXTRAS bonus***\n\n");
	i++;
	real = printf("real%i: mixed %19.42send\n", i, NULL);
	mock = ft_printf("mock%i: mixed %19.42send\n", i, NULL);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: align pad precision %-5.0iend\n", i, 0);
	mock = ft_printf("mock%i: align pad precision %-5.0iend\n", i, 0);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: align pad precision % 05dend\n", i, 0);
	mock = ft_printf("mock%i: align pad precision % 05dend\n", i, 0);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: dash pad pointer %-3pend\n", i, 2);
	mock = ft_printf("mock%i: dash pad pointer %-3pend\n", i, 2);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: pad pointer %5pend\n", i, 2);
	mock = ft_printf("mock%i: pad pointer %5pend\n", i, 2);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	printf("\n*********END*********\n");
}

void	test_print_hash(void)
{
	int	real;
	int	mock;
	int	i;

	i = 0;
	printf("\n***TEST PRINT HASH bonus***\n\n");
	i++;
	real = printf("real%i: hash mix %#24.12Xend\n", i, -534775176);
	mock = ft_printf("mock%i: hash mix %#24.12Xend\n", i, -534775176);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: hashmix2 %#8.2Xend\n", i, -534775176);
	mock = ft_printf("mock%i: hashmix2 %#8.2Xend\n", i, -534775176);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: hash zero pad %#014xend\n", i, 1161871680);
	mock = ft_printf("mock%i: hash zero pad %#014xend\n", i, 1161871680);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: hash zero pad zero %#02Xend\n", i, 0);
	mock = ft_printf("mock%i: hash zero pad zero %#02Xend\n", i, 0);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: zero hash pad zero %0#25Xend\n", i, 0);
	mock = ft_printf("mock%i: zero hash pad zero %0#25Xend\n", i, 0);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: hash %#xend\n", i, 12345);
	mock = ft_printf("mock%i: hash %#xend\n", i, 12345);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	i++;
	real = printf("real%i: hash %0#6xend\n", i, 12345);
	mock = ft_printf("mock%i: hash %0#6xend\n", i, 12345);
	printf("real returned: %i\nmock returned: %i\n\n", real, mock);
	printf("\n*********END*********\n");
}

int 	main(void)
{
	//test_print_chars();
	//test_print_string();
	//test_print_ints();
	//test_print_hexes();
	//test_print_edge();
	//test_print_dash_ints();
	//test_print_dash_chars();
	//test_print_precision();
	//test_print_hash();
	//test_print_extras();
		int a = 50;

	if (printf("real: Test pointers: %p\n", &a) == ft_printf("mock: Test pointers: %p\n", &a))
		printf("\nPASS\n");
	else
		printf("\nFAIL\n");

	if (printf("real: Test long minmax: %p\n", LONG_MIN) == ft_printf("mock: Test long minmax: %p\n", LONG_MIN))
		printf("\nPASS\n");
	else
		printf("\nFAIL\n");

	if (printf("real: Test string: %s\n", "testing123") == ft_printf("mock: Test string: %s\n", "testing123"))
		printf("\nPASS\n");
	else
		printf("\nFAIL\n");
	return (0);
}
