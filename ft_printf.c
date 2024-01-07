/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:04:41 by maweiss           #+#    #+#             */
/*   Updated: 2024/01/07 13:05:53 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// t_arg_spec	ft_get_statement(char *format, t_arg_spec spec)
// {
// 	static char	*del = "0csdiupxX%";
// 	int			len;

// 	len = 0;

// 	while (*format != '\0')
// 	{
// 		while (*format != *del && *del != 0)
// 			del++;
// 		if (*format == *del)
// 			break ;
// 	}
// 	if (format == 0)
// }

/*get the case of the expression*/
int	ft_get_case(char *format)
{
	char		*sub;

	sub = format;
	while (*sub++ != '\0')
	{
		if (*sub == 'c')
			return (1);
		if (*sub == 's')
		{
			//write(1, "Case 2 detected\n", 16);
			return (2);
		}
		if (*sub == 'd' || *sub == 'i')
		{
			//write(1, "Case 3 detected\n", 16);
			return (3);
		}
		if (*sub == 'u')
			return (5);
		if (*sub == 'p')
			return (6);
		if (*sub == 'x')
			return (7);
		if (*sub == 'X')
			return (8);
		if (*sub == '%')
			return (9);
		if (*sub == '\0')
			return (0);
	}
	return (-1);
}

t_arg_spec	ft_init(int *count, int *i)
{
	t_arg_spec	a;

	*count = 0;
	*i = 0;
	a.type = 0;
	a.just = 0;
	a.dot = 0;
	a.shash = 0;
	a.splus = 0;
	a.sspace = 0;
	a.spercent = 0;
}

static int	ft_core(char *s, t_arg_spec spec, va_list args, int *count)
{
	//write(1, "ft core called\n", 15);
	//printf("spec.type = %d\n", spec.type);
	if (spec.type == 1)
	{
		*count += ft_putchar_fd_ret(va_arg(args, int), 1);
	}
	if (spec.type == 2)
	{
		//write(1, "type 2 executed\n", 16);
		*count += ft_putstr_fd_ret(va_arg(args, char*), 1);
	}
	if (spec.type == 3)
	{
		//write(1, "type 3 executed\n", 16);
		*count += ft_itoa_base((unsigned long) va_arg(args, int), "0123456789");
	}
	else
		return (-1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				count;
	int				i;
	t_arg_spec		spec;

	spec = ft_init(&count, &i);
	va_start(args, *s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			spec.type = ft_get_case((char *)s + i);
			//ft_itoa_base(spec.type, "0123456789");
			//write(1, "\n", 1);
			if (spec.type == 9)
			{
				write(1, "%", 1);
				i += 2;
				count += 1;
			}
			if (spec.type != 0 && spec.type != 9)
			{
				ft_core((char *)(s + i + 1), spec, args, &count);
				i += 2;
			}
		}
		else
		{
			write(1, s + i++, 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
