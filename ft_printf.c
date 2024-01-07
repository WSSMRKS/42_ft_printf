/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:04:41 by maweiss           #+#    #+#             */
/*   Updated: 2024/01/07 20:20:09 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_get_case(char *format)
{
	char		*sub;

	sub = format;
	while (*sub++ != '\0')
	{
		if (*sub == 'c')
			return (1);
		if (*sub == 's')
			return (2);
		if (*sub == 'd' || *sub == 'i')
			return (3);
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

static int	ft_core(char *s, t_arg_spec spec, va_list ar, int *count)
{
	long	tmp;

	if (spec.type == 1)
		*count += ft_putchar_fd_ret(va_arg(ar, int), 1);
	if (spec.type == 2)
		*count += ft_putstr_fd_ret(va_arg(ar, char *), 1);
	if (spec.type == 3)
		*count += ft_pnb_b_fd((long) va_arg(ar, int), "0123456789", 1);
	if (spec.type == 5)
		*count += ft_pnb_b_fd((long) va_arg(ar, long), "0123456789", 1);
	if (spec.type == 6)
	{
		tmp = va_arg(ar, long);
		if (tmp == 0)
			*count += ft_putstr_fd_ret("(nil)", 1);
		else
		{
			*count += ft_putstr_fd_ret("0x", 1);
			*count += ft_pnb_b_fd(tmp, "0123456789abcdef", 1);
		}
	}
	if (spec.type == 7)
		*count += ft_pnb_b_fd((long) va_arg(ar, long), "0123456789abcdef", 1);
	if (spec.type == 8)
		*count += ft_pnb_b_fd((long) va_arg(ar, long), "0123456789ABCDEF", 1);
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
			if (spec.type == 0)
				return (-1);
			if (spec.type == 9)
				count += ft_putchar_fd_ret('%', 1);
			if (spec.type != 0 && spec.type != 9)
				ft_core((char *)(s + i + 1), spec, args, &count);
			i += 2; // remember case with only one %
		}
		else
			count += ft_putchar_fd_ret(s[i++], 1);
	}
	va_end(args);
	return (count);
}
