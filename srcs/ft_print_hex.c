/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:28:58 by nozakoya          #+#    #+#             */
/*   Updated: 2021/07/21 15:28:59 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_res(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i)
	{
		ft_putchar_fd(str[i], 1);
		--i;
	}
	ft_putchar_fd(str[i], 1);
}

void	ftputnbr_hex(unsigned int nbr)
{
	char			*str;
	unsigned int	x;
	int				i;

	i = 0;
	str = (char *)malloc(ft_intlen(nbr, 16) + 1);
	if (!str)
		return ;
	while (nbr)
	{
		x = nbr % 16;
		if (x < 10)
			str[i] = x + '0';
		else
			str[i] = x + 87;
		nbr /= 16;
		++i;
	}
	str[i] = '\0';
	ft_res(str);
	free(str);
}

void	ft_low_hex(void)
{
	int				nb;
	unsigned int	nbr;

	nb = va_arg(g_point.ap, int);
	if (nb < 0)
	{
		nbr = (unsigned int)nb;
		ftputnbr_hex(nbr);
	}
	else if (nb == 0)
		ft_putnbr(nb);
	else
		ftputnbr_hex(nb);
}
