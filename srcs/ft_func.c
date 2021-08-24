/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:27:38 by nozakoya          #+#    #+#             */
/*   Updated: 2021/07/21 15:27:42 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		++i;
	return (i);
}

int	ft_intlen(unsigned long nbr, int base)
{
	int	count;

	count = 0;
	while (nbr)
	{
		nbr /= base;
		++count;
	}
	return (count);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
	++g_point.size;
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr_unsigned;

	if (nb < 0)
	{
		nbr_unsigned = (unsigned int)(-1 * nb);
		ft_putchar_fd('-', 1);
	}
	else
		nbr_unsigned = (unsigned int)nb;
	if (nbr_unsigned >= 10)
	{
		ft_putnbr(nbr_unsigned / 10);
		ft_putchar_fd((nbr_unsigned % 10) + '0', 1);
	}
	else
		ft_putchar_fd(nbr_unsigned + '0', 1);
}

void	ft_unsigned_putnbr(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar_fd((nb % 10) + '0', 1);
	}
	else
		ft_putchar_fd(nb + '0', 1);
}
