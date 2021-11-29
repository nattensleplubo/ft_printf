/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:08:42 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/29 15:38:33 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list formatParams, int i, const char *format)
{
	int	ret_val;

	ret_val = 0;
	i++;
	if (format[i] == 'c')
		ret_val += ft_print_char(formatParams);
	else if (format[i] == 's')
		ret_val += ft_print_str(formatParams);
	else if (format[i] == 'p')
		ret_val += 2 + ft_print_pointer(formatParams);
	else if (format[i] == 'd' || format[i] == 'i')
		ret_val += ft_print_decimal(formatParams);
	else if (format[i] == 'u')
		ret_val += ft_print_unsigned(formatParams);
	else if (format[i] == 'x')
		ret_val += ft_putnbr_hex(formatParams, "0123456789abcdef");
	else if (format[i] == 'X')
		ret_val += ft_putnbr_hex(formatParams, "0123456789ABCDEF");
	else if (format[i] == '%')
		ret_val += ft_putchar('%');
	return (ret_val - 2);
}

// ##################### MAIN FUNCTION ##################### //

int	ft_printf(const char *format, ...)
{
	va_list		format_params;
	int			i;
	int			ret_val;

	va_start (format_params, format);
	i = 0;
	ret_val = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret_val += ft_parse(format_params, i, format);
			i++;
			ret_val++;
		}
		else
			ft_putchar(format[i]);
		i++;
		ret_val++;
	}
	return (ret_val);
}

// int	main(void)
// {
// 	int	i;
// 	int j;

// 	i = printf("%x", -0);
// 	printf("\n");
// 	j = ft_printf("%x", -0);
// 	printf("\n");

// 	ft_printf("Vrai : %d\nMoi  : %d\n", i, j);
// }