/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:33:53 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/04/05 12:21:06 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	int	write_check;

	write_check = write(1, &c, 1);
	if (write_check == -1)
		return (-1);
	return (1);
}

int	ft_print_percent(void)
{
	int	write_check;

	write_check = write(1, "%", 1);
	if (write_check == -1)
		return (-1);
	return (1);
}

int	ft_print_string(char *c)
{
	size_t	i;
	int		write_check;

	i = 0;
	if (c == NULL)
		return (write(1, "(null)", 6));
	while (c[i] != '\0')
	{
		write_check = write(1, &c[i], 1);
		if (write_check == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int i)
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
	length += ft_print_unsigned(i / 10);
	if (length == -1)
		return (-1);
	c = i % 10 + '0';
	write_check = write(1, &c, 1);
	if (write_check == -1)
		return (-1);
	return (length + 1);
}
