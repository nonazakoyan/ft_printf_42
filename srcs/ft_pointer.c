/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:28:37 by nozakoya          #+#    #+#             */
/*   Updated: 2021/07/21 15:28:40 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftputnbr_pointer(unsigned long nbr)
{
	char			*str;
	unsigned long	x;
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

void	ft_pointer(void)
{
	unsigned long	nb;

	nb = va_arg(g_point.ap, unsigned long);
	write (1, "0x", 2);
	g_point.size += 2;
	if (nb == 0)
		ft_putnbr(nb);
	else
		ftputnbr_pointer(nb);
}
