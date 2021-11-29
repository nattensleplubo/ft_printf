/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:14:29 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/29 12:14:30 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(va_list formatParams)
{
	int	i;

	i = (int)va_arg(formatParams, int);
	ft_putnbr(i);
	return (ft_len(i));
}

int	ft_putnbr_hex(va_list formatParams, char *base)
{
	int	i;

	i = (int)va_arg(formatParams, int);
	ft_putnbr_base(i, base);
	return (ft_hex_len(i));
}

int	ft_print_unsigned(va_list formatParams)
{
	int	i;

	i = (unsigned int)va_arg(formatParams, unsigned int);
	ft_putunsigned(i);
	return (ft_len_unsigned(i));
}

int	ft_print_pointer(va_list formatParams)
{
	unsigned long	i;

	i = (unsigned long)va_arg(formatParams, unsigned long);
	ft_putstr("0x");
	ft_putpointer(i, "0123456789abcdef");
	if (!i)
		return (ft_ptr_len(i) + 1);
	else
		return (ft_ptr_len(i));
}