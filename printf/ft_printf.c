/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:02:50 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/04/05 11:46:31 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(const char *s, va_list arg)
{
	int	len;

	len = 0;
	if (*s == 'c')
		len += ft_print_char(va_arg(arg, int));
	else if (*s == 's')
		len += ft_print_string(va_arg(arg, char *));
	else if (*s == 'd' || *s == 'i')
		len += ft_print_nbr(va_arg(arg, int));
	else if (*s == 'u')
		len += (ft_print_unsigned(va_arg(arg, unsigned int)));
	else if (*s == 'x')
		len += ft_print_hex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (*s == 'X')
		len += ft_print_hex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (*s == 'p')
		len += ft_print_pointer(va_arg(arg, unsigned long long),
				"0123456789abcdef");
	else if (*s == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		final;

	final = 0;
	if (str == NULL)
		return (-1);
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			final += ft_checker(str, va);
			if (final == -1)
				break ;
		}
		else
			final += write(1, str, 1);
		if (final == -1)
			break ;
		str++;
	}
	va_end(va);
	return (final);
}
