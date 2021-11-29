/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:08:42 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/29 12:15:45 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list formatParams, int i, const char *format)
{
	int	retVal;

	retVal = 0;
	i++;
	if (format[i] == 'c')
		retVal += ft_print_char(formatParams);
	else if (format[i] == 's')
		retVal += ft_print_str(formatParams);
	else if (format[i] == 'p')
		retVal += 2 + ft_print_pointer(formatParams);
	else if (format[i] == 'd' || format[i] == 'i')
		retVal += ft_print_decimal(formatParams);
	else if (format[i] == 'u')
		retVal += ft_print_unsigned(formatParams);
	else if (format[i] == 'x')
		retVal += ft_putnbr_hex(formatParams, "0123456789abcdef");
	else if (format[i] == 'X')
		retVal += ft_putnbr_hex(formatParams, "0123456789ABCDEF");
	else if (format[i] == '%')
		retVal += ft_putchar('%');
	return (retVal - 2);
}

// ##################### MAIN FUNCTION ##################### //

int	ft_printf(const char *format, ...)
{
	va_list		formatParams;
	int			i;
	int			retVal;
	va_start	(formatParams, format);

	i = 0;
	retVal = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			retVal += ft_parse(formatParams, i, format);
			i++;
			retVal++;
		}
		else
			ft_putchar(format[i]);
		i++;
		retVal++;
	}
	return (retVal);
}

int	main(void)
{
	int	i;
	int j;
	// int	d = 42;
	// unsigned int u = 1337;
	
	i = printf("%p", NULL);
	printf("\n");
	j = ft_printf("%p", NULL);
	printf("\n");

	ft_printf("Vrai : %d\nMoi  : %d\n", i, j);
}