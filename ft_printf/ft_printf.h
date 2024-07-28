/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:51:03 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/03/28 18:15:01 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_checker(const char *s, va_list arg);
int	ft_printf(const char *str, ...);
int	ft_print_char(int c);
int	ft_print_percent(void);
int	ft_print_string(char *c);
int	ft_print_nbr(int i);
int	ft_print_unsigned(unsigned int i);
int	ft_print_hex(unsigned int nbr, const char *base);
int	ft_print_pointer(unsigned long long i, char *base);

#endif