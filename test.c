/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:04:54 by maweiss           #+#    #+#             */
/*   Updated: 2024/01/14 19:02:51 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char 	p;
	char 	*pp;
	int		ret;

	setbuf(stdout, NULL);
	p = 42;
	pp = &p;

	printf("\n#01\n");
	printf("Built in:\n");
	ret = printf("%", pp);
	printf("\nReturn value: %d\n", ret);
	ft_printf("selfmade:\n");
	ft_printf("%", pp);
	ret = ft_printf("%", pp);
	ft_printf("\nReturn value: %d\n", ret);
	
	printf("\n#01.1\n");
	printf("Built in:\n");
	ret = printf("1234%", pp);
	printf("\nReturn value: %d\n", ret);
	ft_printf("selfmade:\n");
	ft_printf("1234%", pp);
	ret = ft_printf("%", pp);
	ft_printf("\nReturn value: %d\n", ret);

	printf("\n#01.2\n");
	printf("Built in:\n");
	ret = printf("%c", 0);
	printf("\nReturn value: %d\n", ret);
	ft_printf("selfmade:\n");
	ft_printf("%c", 0);
	ret = ft_printf("%c", 0);
	ft_printf("\nReturn value: %d\n", ret);
	
	printf("\n#02\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%%%", pp));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%%%", pp));
	printf("\n#03\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("", pp));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("", pp));
	printf("\n#04\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("\0\n", pp));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("\0\n", pp));
	printf("\n#05\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("\n", pp));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("\n", pp));
	printf("\n#06\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%"));
	printf("\n#07\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%%%"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%%%"));
	printf("\n#08\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(""));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(""));
	printf("\n#09\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("\0\n"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("\0\n"));
	printf("\n#10\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("\n"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("\n"));
	printf("\n#11\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", pp));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", pp));
	printf("\n#12\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", NULL));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", NULL));
	printf("\n#13\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", (void *) 0));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", (void *) 0));
	printf("\n#14\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%X\n", 5565));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%X\n", 5565));
	printf("\n#15\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", -5555));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", -5555));
	printf("\n#16\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%x\n", 256585));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%x\n", 256585));
	printf("\n#17\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", pp));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", pp));
	printf("\n#18\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%d\n", 154));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%d\n", 154));
	printf("\n#19\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%u\n", 4294967295));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%u\n", 4294967295));
	printf("\n#20\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%i\n", -154));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%i\n", -154));
	printf("\n#21\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%s", "this is the string to print\n"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%s", "this is the string to print\n"));
	printf("\n#22\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%s\n%d\n%i\n%u\n%c\n%%\n", "this is the string to print", 12345, -222, 4294967295, 'a'));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%s\n%d\n%i\n%u\n%c\n%%\n", "this is the string to print", 12345, -222, 4294967295, 'a'));
	printf("\n#23\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%s\n%u\n%u\n%u\n%c\n%%\n", "this is the string to print", 12345, -222, 4294967295, 'a'));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%s\n%u\n%u\n%u\n%c\n%%\n", "this is the string to print", 12345, -222, 4294967295, 'a'));
	printf("\n#23.1\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%s\n", 0));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%s\n", 0));
	printf("\n#23.2\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", 0));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", 0));

	printf("\n#24 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" NULL %s NULL ", NULL));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" NULL %s NULL ", NULL));

	printf("\n#25 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %p %p ", LONG_MIN, LONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));

	printf("\n#26 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));

	printf("\n#27 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u ", LONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u ", LONG_MAX));

	printf("\n#28 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u ", LONG_MIN));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u ", LONG_MIN));

	printf("\n#29 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u ", ULONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u ", ULONG_MAX));

	printf("\n#30 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u ", 9223372036854775807LL));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u ", 9223372036854775807LL));

	printf("\n#31 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX,
LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX,
LONG_MIN, ULONG_MAX, 0, -42));

	printf("\n#32 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x ", LONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x ", LONG_MAX));

	printf("\n#33 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x ", LONG_MIN));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x ", LONG_MIN));

	printf("\n#34 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x ", ULONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x ", ULONG_MAX));

	printf("\n#35 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x ", 9223372036854775807LL));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x ", 9223372036854775807LL));

	printf("\n#36 Francinette errors\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX,
LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX,
LONG_MIN, ULONG_MAX, 0, -42));
}


	// ppp = &pp;
	// write(1, &p, 1);
	// write(1, &pp, 7);
	// ft_itoa_base((unsigned long) pp, "0123456789abcdef");
	// write(1, "\n", 1);
	// printf("01: %p\n", pp);
	// printf("02: \"%20.15d\"", (int) p);
	// printf("\n");
	// printf("03: \"%-20.15d\"", (int) p);
	// printf("\n");
	// printf("04: \"% -20.15d\"", (int) p);
	// printf("\n");
	// printf("04.1: \"% -20.15d\"", (int) p);
	// printf("\n");
	// printf("04.2: \"%-20.15d\"", (int) p);
	// printf("\n");
	// printf("04.3: \"%#.60x\"", (unsigned int) p);
	// printf("\n");
	// printf("06: \"%10.5d\"", (int) p);
	// printf("\n");
	// printf("07: \"%-10.5d\"", (int) p);
	// printf("\n");
	// printf("08: \"%-10d\"", (int) p);
	// printf("\n");
	// printf("09: \"%010 \"", (int) p);
	// printf("\n");
	// printf("10: \"hallo tahis dlsjf% 10 d%\"", (int) p);
	// printf("\n");
	// printf("11: \"hallo tahis dlsjf%-     10.d%\"", (int) p);
	// printf("\n");
	// printf("12: \"hallo tahis\0 dlsjf\"");
	// printf("\n");
