/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:04:41 by maweiss           #+#    #+#             */
/*   Updated: 2023/12/15 23:03:19 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_arg_spec
{
	int		type;
	int		just;		// -		number of padding spaces neg = alligned left
	int		dot;		// .		number of leading zeroes
	int		shash;	// #		yes or no	0x in types x or X
	int		splus;	// plus:	yes or no	plus if value positive
	int		sspace;	// space:	yes or no	space if value positive (ignored in x and X)
	int		spercent;	// print percent sign
}				t_arg_spec;
#endif

t_arg_spec	ft_get_statement(char *format, t_arg_spec spec)
{
	static char	*del = "0csdiupxX%";
	int			len;

	len = 0;

	while (*format != '\0')
	{
		while (*format != *del && *del != 0)
			del++;
		if (*format == *del)
			break;
		len++;
		if (*format == '-')
			spec.just = -1;
		if (*format == '.')
			spec.dot = 0;
		format++;
	}
}

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

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				count;
	int				i;
	t_arg_spec		spec;
	int				type;

	spec = ft_init(&count, &i);
	va_arg(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			spec.type = ft_get_case(s + i);
			if (type == 9)
				i++;
			if (type != 0 && type != 9)
				i = i + ft_core((s + i + 1), spec, args);
		}
		else
			write(1, s + i++, 1);
	}
	va_end(args);
	return (i + 1);
}
