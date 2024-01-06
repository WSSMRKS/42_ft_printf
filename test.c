/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:04:54 by maweiss           #+#    #+#             */
/*   Updated: 2024/01/06 20:13:05 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char p;
	char *pp;
	// char **ppp;

	p = 42;
	pp = &p;
	// ppp = &pp;
	// write(1, &p, 1);
	// write(1, &pp, 7);
	ft_itoa_base((unsigned long) pp, "0123456789abcdef");
	write(1, "\n", 1);
	printf("01: %p\n", pp);
	printf("02: \"%20.15d\"", (int) p);
	printf("\n");
	printf("03: \"%-20.15d\"", (int) p);
	printf("\n");
	printf("04: \"% -20.15d\"", (int) p);
	printf("\n");
	printf("04.1: \"% -20.15d\"", (int) p);
	printf("\n");
	printf("04.2: \"%-20.15d\"", (int) p);
	printf("\n");
	printf("04.3: \"%#.60x\"", (unsigned int) p);
	printf("\n");
	printf("06: \"%10.5d\"", (int) p);
	printf("\n");
	printf("07: \"%-10.5d\"", (int) p);
	printf("\n");
	printf("08: \"%-10d\"", (int) p);
	printf("\n");
	printf("09: \"%010 \"", (int) p);
	printf("\n");
	printf("10: \"hallo tahis dlsjf% 10 d%\"", (int) p);
	printf("\n");
	printf("11: \"hallo tahis dlsjf%-     10.d%\"", (int) p);
	printf("\n");
	printf("12: \"hallo tahis\0 dlsjf\"");
	printf("\n");

	ft_printf("%%");

	// printf("%p\n", pp);
	// printf("%p\n", ppp);
}
