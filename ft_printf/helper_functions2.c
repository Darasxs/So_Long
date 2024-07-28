/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:33:46 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/04/05 12:19:11 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, const char *base)
{
	int	length;
	int	write_check;

	length = 0;
	if (nbr < 16)
	{
		write_check = write(1, &base[nbr % 16], 1);
		if (write_check == -1)
			return (-1);
		return (length + 1);
	}
	length += ft_print_hex(nbr / 16, base);
	if (length == -1)
		return (-1);
	write_check = write(1, &base[nbr % 16], 1);
	if (write_check == -1)
		return (-1);
	return (length + 1);
}

int static	ft_pointer_helper(unsigned long long i, char *base, int *length)
{
	int	write_check;

	if (i > 0)
	{
		ft_pointer_helper(i / 16, base, length);
		write_check = write(1, &base[i % 16], 1);
		if (write_check == -1)
			return (-1);
		(*length)++;
	}
	return (*length);
}

int	ft_print_pointer(unsigned long long i, char *base)
{
	int	length;
	int	write_check;

	write_check = write(1, "0x", 2);
	if (write_check == -1)
		return (-1);
	length = 2;
	if (i == 0)
	{
		write_check = write(1, "0", 1);
		if (write_check == -1)
			return (-1);
		length++;
	}
	else if (i > 0)
		ft_pointer_helper(i, base, &length);
	return (length);
}

int static	ft_nbr_helper(int i)
{
	int		length;
	int		write_check;
	char	c;

	length = 0;
	if (i < 10)
	{
		c = i + '0';
		write_check = write(1, &c, 1);
		if (write_check == -1)
			return (-1);
		return (length + 1);
	}
	length += ft_nbr_helper(i / 10);
	if (length == -1)
		return (-1);
	c = i % 10 + '0';
	write_check = write(1, &c, 1);
	if (write_check == -1)
		return (-1);
	return (length + 1);
}

int	ft_print_nbr(int i)
{
	int	length;
	int	write_check;

	length = 0;
	if (i == -2147483648)
	{
		write_check = write(1, "-2147483648", 11);
		if (write_check == -1)
			return (-1);
		return (11);
	}
	if (i < 0)
	{
		write_check = write(1, "-", 1);
		if (write_check == -1)
			return (-1);
		i = -i;
		length++;
	}
	length += (ft_nbr_helper(i));
	return (length);
}
