/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:06:46 by maweiss           #+#    #+#             */
/*   Updated: 2024/01/08 15:43:31 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_arg_spec
{
	int		type;
	int		just;
	int		dot;
	int		shash;
	int		splus;
	int		sspace;
	int		spercent;
}				t_arg_spec;

int	ft_printf(const char *s, ...);
int	ft_pnb_b_fd(long nbr, char *base, int fd);
int	ft_putstr_fd_ret(char *s, int fd);
int	ft_putchar_fd_ret(char c, int fd);
#endif