/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upperhex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:29:24 by nozakoya          #+#    #+#             */
/*   Updated: 2021/07/21 15:29:26 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftputnbr_upperhex(unsigned int nbr)
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
			str[i] = x + 55;
		nbr /= 16;
		++i;
	}
	str[i] = '\0';
	ft_res(str);
	free(str);
}

void	ft_upper_hex(void)
{
	int				nb;
	unsigned int	nbr;

	nb = va_arg(g_point.ap, int);
	if (nb < 0)
	{
		nbr = (unsigned int)nb;
		ftputnbr_upperhex(nbr);
	}
	else if (nb == 0)
		ft_putnbr(nb);
	else
		ftputnbr_upperhex(nb);
}
