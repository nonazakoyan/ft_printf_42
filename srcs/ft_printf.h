/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:28:21 by nozakoya          #+#    #+#             */
/*   Updated: 2021/07/21 15:28:23 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	va_list	ap;
	void	*arg;
	int		size;
	char	*s;
}			t_list;

t_list	g_point;
int		ft_printf(const char *str, ...);
void	ft_check_description(char c);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
void	ft_unsigned_putnbr(unsigned int nb);
void	ft_putchar_fd(char c, int fd);
int		ft_intlen(unsigned long nbr, int base);
void	ftputnbr_hex(unsigned int nbr);
void	ftputnbr_upperhex(unsigned int nbr);
void	ftputnbr_pointer(unsigned long nbr);
void	ft_res(char *str);
void	ft_char(void);
void	ft_string(void);
void	ft_pointer(void);
void	ft_integer(void);
void	ft_unsigned_int(void);
void	ft_low_hex(void);
void	ft_upper_hex(void);
void	ft_percent(void);

#endif
