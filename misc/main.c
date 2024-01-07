/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:02:09 by maweiss           #+#    #+#             */
/*   Updated: 2024/01/07 17:28:07 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main (void)
{
	/* 1. */
	char c;

	c = 'a';
	printf("%c\n", c);
	c = '-';
	printf("%c\n", c);
	c = 0;
	printf("%c\n", c);
	c = 35;
	printf("%c\n", c);
	c = 7;
	printf("%c\n", c);
	c = 31;
	printf("%c\n", c);
	c = 127;
	printf("%c\n", c);

	/*durch putchar abgedeckt*/

	/* 2. */
	printf("%s\n","schauen wir mal wie wie den gedruckt");
	printf("%s\n","Hallo");
	printf("%s\n","83736284dkddnurt");
	printf("%s\n","Was passiert bei non printables?");
	printf("%s\n","was passiert wenn Str leer ist?");
	printf("%s\n","");
	printf("%s\n","_");

	/*groestenteils durch putstring abgedeckt*/

	/* 3. */
	static char *test = "Teststring!";
	char p;
	char *pp;
	char **ppp;

	p = 42;
	pp = &p;
	ppp = &pp;
	printf("%p\n", test);
	printf("%p\n", &test[4]);
	printf("%p\n", &test[0]);
	printf("%p\n", &test[2]);
	printf("%p\n", &test[3]);
	printf("%p\n", &p);
	printf("%p\n", p);
	printf("%p\n", pp);
	printf("%p\n", ppp);

	/*Memory Adresse drucken, bisher noch nicht gemacht.*/

	/* 4. */
	int nb;

	nb = -2147483648;
	printf("%d\n", nb);
	nb = 2147483647;
	printf("%d, %d, %d\n", nb, nb, nb);
	nb = 0;
	printf("%d\n", nb);
	nb = -1;
	printf("%d\n", nb);
	nb = 1;
	printf("%d, %d\n", nb, nb);
	nb = 11000010;
	printf("%d\n", nb);

	/*Durch putnbr abgedeckt. was ist mit size_t und longlong / long */

	/* 5. */

	/* same as 4. */

	/* 6. , 7., 8. */

	// %u Prints an unsigned decimal (base 10) number.

	/*Cover with ft_itoa_base (need to code!)*/

	/* 9. */

	/* Cover with putchar */

	

}
