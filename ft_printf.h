/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:06:46 by maweiss           #+#    #+#             */
/*   Updated: 2024/01/07 11:42:11 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_arg_spec
{
	int		type;		// case
	int		just;		// -		number of padding spaces neg = alligned left
	int		dot;		// .		number of leading zeroes
	int		shash;	// #		yes or no	0x in types x or X
	int		splus;	// plus:	yes or no	plus if value positive
	int		sspace;	// space:	yes or no	space if value positive (ignored in x and X)
	int		spercent;	// print percent sign
}				t_arg_spec;

int	ft_printf(const char *s, ...);
int	ft_itoa_base(unsigned long nbr, char *base);
int	ft_putstr_fd_ret(char *s, int fd);
int	ft_putchar_fd_ret(char c, int fd);


#endif