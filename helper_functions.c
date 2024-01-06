/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:43:43 by maweiss           #+#    #+#             */
/*   Updated: 2024/01/06 20:03:28 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_ret(char *s, int fd)
{
	int		strlen;
	int		i;

	i = 0;
	strlen = 0;
	while (s[i] != '\0')
	{
		strlen++;
		i++;
	}
	write(fd, s, strlen);
	return (strlen);
}

int	ft_putchar_fd_ret(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
