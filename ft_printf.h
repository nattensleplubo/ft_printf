/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:45:10 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/29 15:41:35 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_len(int n);
int		ft_len_unsigned(unsigned int n);
int		ft_hex_len(unsigned	int num);
int		ft_ptr_len(unsigned long num);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putnbr_base(unsigned int nb, char *base);
void	ft_putunsigned(unsigned int n);
void	ft_putpointer(unsigned long nb, char *base);
int		ft_print_char(va_list formatParams);
int		ft_print_str(va_list formatParams);
int		ft_print_decimal(va_list formatParams);
int		ft_putnbr_hex(va_list formatParams, char *base);
int		ft_print_unsigned(va_list formatParams);
int		ft_print_pointer(va_list formatParams);
int		ft_parse(va_list formatParams, int i, const char *format);

int		ft_printf(const char *format, ...);

#endif