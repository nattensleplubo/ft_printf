/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:09:14 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/25 17:30:56 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//###################### MALLOC FUNCTIONS ###################### //


//##################### EXTERNAL FUNCTIONS ##################### //

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int n)
{
	char	c;

	c = n % 10 + '0';
	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		write(1, "8", 1);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * -1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}

// ##################### FLAGS FUNCTIONS ##################### //

void	ft_print_char(va_list formatParams) // For %c
{
	char	c;

	c = (char)va_arg(formatParams, int);
	ft_putchar(c);
}

void	ft_print_str(va_list formatParams)
{
	ft_putstr((char *)va_arg(formatParams, char *));
}

void	ft_print_decimal(va_list formatParams)
{
	ft_putnbr((int)va_arg(formatParams, int));
}

// ################### PARSING FUNCTION ################### //

void	ft_parse(va_list formatParams, int i, const char *format)
{
	i++;
	if (format[i] == 'c')
		ft_print_char(formatParams);
	else if (format[i] == 's')
		ft_print_str(formatParams);
	// else if (format[i] == 'p')
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_decimal(formatParams);
	// else if (format[i] == 'u')
	// else if (format[i] == 'x')
	// else if (format[i] == '%')
}

// ##################### MAIN FUNCTION ##################### //

int	ft_printf(const char *format, ...)
{
	va_list		formatParams;
	int			i;
	va_start	(formatParams, format);

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_parse(formatParams, i, format);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	return (1);
}

int	main(void)
{
	ft_printf("%i %i %i", 42, 42 ,42);
}