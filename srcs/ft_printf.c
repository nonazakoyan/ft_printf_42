/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:28:05 by nozakoya          #+#    #+#             */
/*   Updated: 2021/07/21 15:28:08 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_description(char c)
{
	if (c == 'c')
		ft_char();
	else if (c == 's')
		ft_string();
	else if (c == 'p')
		ft_pointer();
	else if (c == 'd' || c == 'i')
		ft_integer();
	else if (c == 'u')
		ft_unsigned_int();
	else if (c == 'x')
		ft_low_hex();
	else if (c == 'X')
		ft_upper_hex();
	else if (c == '%')
		ft_percent();
}

int	ft_printf(const char *str, ...)
{
	g_point.size = 0;
	va_start(g_point.ap, str);
	g_point.s = (char *)str;
	while (*g_point.s)
	{
		if (*g_point.s == '%')
		{
			++g_point.s;
			ft_check_description(*g_point.s);
			++g_point.s;
		}
		else
		{
			ft_putchar_fd(*g_point.s, 1);
			++g_point.s;
		}
	}
	va_end(g_point.ap);
	return (g_point.size);
}
