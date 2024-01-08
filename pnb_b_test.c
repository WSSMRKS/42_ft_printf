#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	ft_pnb_b_fd(-9223372036854775808, "0123456789abcdef", 1);
	write(1, "\n", 1);
	ft_pnb_b_fd(-2147483647, "0123456789abcdef", 1);
	write(1, "\n", 1);
	ft_pnb_b_fd(LONG_MIN, "0123456789abcdef", 1);
	write(1, "\n", 1);
	ft_pnb_b_fd(LONG_MIN, "0123456789", 1);
	write(1, "\n", 1);
	printf("%p\n", -9223372036854775808);
	printf("%p\n", -2147483647);
	printf("%p\n", LONG_MIN);
	printf("%lu\n", LONG_MIN);
	
}