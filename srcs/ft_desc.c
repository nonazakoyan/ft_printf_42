/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_desc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:27:12 by nozakoya          #+#    #+#             */
/*   Updated: 2021/07/22 17:37:12 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(void)
{
	char	c;

	c = va_arg(g_point.ap, int);
	ft_putchar_fd(c, 1);
}

void	ft_string(void)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(g_point.ap, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		g_point.size += 6;
	}
	while (i < ft_strlen(s))
	{
		ft_putchar_fd(s[i], 1);
		++i;
	}
}

void	ft_unsigned_int(void)
{
	unsigned int	nbr;

	nbr = va_arg(g_point.ap, unsigned int);
	ft_unsigned_putnbr(nbr);
}

void	ft_integer(void)
{
	int	dec;

	dec = va_arg(g_point.ap, int);
	ft_putnbr(dec);
}

void	ft_percent(void)
{
	ft_putchar_fd('%', 1);
}
