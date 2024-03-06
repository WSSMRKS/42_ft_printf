/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:04:54 by maweiss           #+#    #+#             */
/*   Updated: 2024/03/06 11:31:05 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char	p;
	char	*pp;
	int		ret;

	setbuf(stdout, NULL);
	p = 42;
	pp = &p;
	printf("Detailed Tests");
	printf("\n#01\n%%, pp\n");
	printf("Built in:\n");
	ret = printf("%", pp);
	printf("\nReturn value: %d\n", ret);
	ft_printf("selfmade:\n");
	ft_printf("%", pp);
	ret = ft_printf("%", pp);
	ft_printf("\nReturn value: %d\n", ret);

	printf("\n#01.1\n1234%%, pp\n");
	printf("Built in:\n");
	ret = printf("1234%", pp);
	printf("\nReturn value: %d\n", ret);
	ft_printf("selfmade:\n");
	ft_printf("1234%", pp);
	ret = ft_printf("%", pp);
	ft_printf("\nReturn value: %d\n", ret);

	printf("\n#01.2\n%%c, 0\n");
	printf("Built in:\n");
	ret = printf("%c", 0);
	printf("\nReturn value: %d\n", ret);
	ft_printf("selfmade:\n");
	ft_printf("%c", 0);
	ret = ft_printf("%c", 0);
	ft_printf("\nReturn value: %d\n", ret);

	printf("\n#02\n%%%%%%, pp\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%%%", pp));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%%%", pp));
	printf("\n#02.01\n%%%%, pp\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%%", pp));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%%", pp));
	printf("\n#02.1\nthis is not defined %%l How is it gonna behave?, pp\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("this is not defined %l How is it gonna behave?", pp));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("this is not defined %l How is it gonna behave?", pp));
	printf("\n#03\n\"\"\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("", pp));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("", pp));
	printf("\n#04\n\\0\\n, pp\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("\0\n", pp));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("\0\n", pp));
	printf("\n#05\n\\n, pp\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("\n", pp));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("\n", pp));
	printf("\n#06\n%%\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%"));
	printf("\n#07\n%%%%%%\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%%%"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%%%"));
	printf("\n#08\n\"\"\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(""));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(""));
	printf("\n#09\n\\0\\n\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("\0\n"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("\0\n"));
	printf("\n#10\n\\n\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("\n"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("\n"));
	printf("\n#11\n%%p\\n, pp\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", pp));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", pp));
	printf("\n#12\n%%p\\n, NULL\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", NULL));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", NULL));
	printf("\n#13\n%%p\\n, (void *) 0\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", (void *) 0));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", (void *) 0));
	printf("\n#14\n%%X\\n, 5565\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%X\n", 5565));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%X\n", 5565));
	printf("\n#15\n%%p\\n, -5555\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", -5555));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", -5555));
	printf("\n#16\n%%x\\n, 256585\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%x\n", 256585));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%x\n", 256585));
	printf("\n#17\n%%p\\n, pp\n pp = the adress of p");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", pp));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", pp));
	printf("\n#18\n%%d\\n, 154\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%d\n", 154));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%d\n", 154));
	printf("\n#19\n%%u\\n, 4294967295");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%u\n", 4294967295));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%u\n", 4294967295));
	printf("\n#20\n%%i\\n, -154\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%i\n", -154));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%i\n", -154));
	printf("\n#21\n%%s, \"this is the string to print\\n\"\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%s", "this is the string to print\n"));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%s", "this is the string to print\n"));
	printf("\n#22\n%%s\\n%%d\\n%%i\\n%%u\\n%%c\\n%%\\n, \"this is the string to print\", 12345, -222, 4294967295, 'a'\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%s\n%d\n%i\n%u\n%c\n%%\n", "this is the string to print", 12345, -222, 4294967295, 'a'));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%s\n%d\n%i\n%u\n%c\n%%\n", "this is the string to print", 12345, -222, 4294967295, 'a'));
	printf("\n#23\n%%s\\n%%u\\n%%u\\n%%u\\n%%c\\n%%\\n, \"this is the string to print\", 12345, -222, 4294967295, 'a'\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%s\n%u\n%u\n%u\n%c\n%%\n", "this is the string to print", 12345, -222, 4294967295, 'a'));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%s\n%u\n%u\n%u\n%c\n%%\n", "this is the string to print", 12345, -222, 4294967295, 'a'));
	printf("\n#23.1\n%%s\\n, 0\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%s\n", 0));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%s\n", 0));
	printf("\n#23.2\n%%p\\n, 0\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf("%p\n", 0));
	printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf("%p\n", 0));

	printf("\n#24 Francinette errors\n NULL %%s NULL , NULL\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" NULL %s NULL ", NULL));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" NULL %s NULL ", NULL));

	printf("\n#25 Francinette errors\n%%p %%p , LONG_MIN, LONG_MAX\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %p %p ", LONG_MIN, LONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));

	printf("\n#26 Francinette errors\n%%p %%p , ULONG_MAX, -ULONG_MAX\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));

	printf("\n#27 Francinette errors\n%%u , LONG_MAX\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u ", LONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u ", LONG_MAX));

	printf("\n#28 Francinette errors\n%%u , LONG_MIN\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u ", LONG_MIN));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u ", LONG_MIN));

	printf("\n#29 Francinette errors\n%%u , ULONG_MAX)\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u ", ULONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u ", ULONG_MAX));

	printf("\n#30 Francinette errors\n%%u , 9223372036854775807LL\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u ", 9223372036854775807LL));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u ", 9223372036854775807LL));

	printf("\n#31 Francinette errors\n%%u %%u %%u %%u %%u %%u %%u, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX,
			LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX,
			LONG_MIN, ULONG_MAX, 0, -42));

	printf("\n#32 Francinette errors\n%%x , LONG_MAX\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x ", LONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x ", LONG_MAX));

	printf("\n#33 Francinette errors\n%%x , LONG_MIN\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x ", LONG_MIN));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x ", LONG_MIN));

	printf("\n#34 Francinette errors\n%%x , ULONG_MAX\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x ", ULONG_MAX));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x ", ULONG_MAX));

	printf("\n#35 Francinette errors\n %%x , 9223372036854775807LL\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x ", 9223372036854775807LL));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x ", 9223372036854775807LL));

	printf("\n#36 Francinette errors\n%%x %%x %%x %%x %%x %%x %%x, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX,
			LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX,
			LONG_MIN, ULONG_MAX, 0, -42));
	printf("\n#37: %%d, -2147483648\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(" %d", -2147483648));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(" %d", -2147483648));
	printf("\n#38: printf(0)\n");
	printf("Built in:\n");
	printf("\nReturn value: %d\n", printf(0));
	ft_printf("selfmade:\n");
	ft_printf("\nReturn value: %d\n", ft_printf(0));
}
