/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:11:04 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/29 12:44:58 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}

int	ft_print_char(va_list formatParams)
{
	char	c;

	c = (char)va_arg(formatParams, int);
	return (ft_putchar(c));
}

int	ft_print_str(va_list formatParams)
{
	int	i;

	if (!((char *)va_arg(formatParams, char *)))
	{
		ft_putstr("(null)");
		return (6);
	}
	i = ft_putstr((char *)va_arg(formatParams, char *));
	return (i);
}
