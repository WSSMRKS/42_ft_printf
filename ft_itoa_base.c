/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:35:05 by maweiss           #+#    #+#             */
/*   Updated: 2024/01/06 20:01:53 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_strlen_check(char *str)
{
	int	strlen;
	int	i;
	int	j;

	i = 0;
	strlen = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+' )
			return (-1);
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == str[i] && i != j && str[i] != 0)
				return (-1);
			j++;
		}
		strlen++;
		str++;
	}
	if (strlen <= 1)
		return (-1);
	return (strlen);
}

unsigned long	ft_neg(unsigned long nbr)
{
	unsigned long	u_inp;

	if (nbr < 0)
	{
		u_inp = nbr * -1;
		ft_putchar_fd('-', 0);
	}
	else
		u_inp = nbr;
	return (u_inp);
}

int	ft_power(unsigned long nbr, int b_len)
{
	int	power;

	power = 0;
	while (nbr >= (unsigned long) b_len)
	{
		nbr /= b_len;
		power++;
	}
	return (power);
}

int	ft_ret(unsigned long nbr, int u_inp, int b_len)
{
	if (nbr != u_inp)
		return (ft_power(u_inp, b_len) + 2);
	else
		return (ft_power(u_inp, b_len) + 1);
}

int	ft_itoa_base(unsigned long nbr, char *base)
{
	int				b_len;
	int				power;
	unsigned long	tmp;
	int				div_count;
	unsigned long	u_inp;

	b_len = 0;
	b_len = ft_strlen_check(base);
	if (b_len < 0)
		return ;
	u_inp = ft_neg(nbr);
	power = ft_power(u_inp, b_len);
	while (power >= 0)
	{
		div_count = power;
		tmp = u_inp;
		while (div_count > 0)
		{
			tmp /= b_len;
			div_count--;
		}
		ft_putchar_fd(base[tmp % b_len], 0);
		power--;
	}
	return (ft_ret(nbr, u_inp, b_len));
}
