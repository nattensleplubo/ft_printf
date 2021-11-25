/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:09:14 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/25 16:12:22 by ngobert          ###   ########.fr       */
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

// ##################### PARSING FUNCTIONS ##################### //

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

void	ft_parse(va_list formatParams, int i, const char *format)
{
	i++;
	if (format[i] == 'c')
		ft_print_char(formatParams);
	else if (format[i] == 's')
		ft_print_str(formatParams);
	// else if (format[i] == 'p')
	// else if (format[i] == 'd')
	// else if (format[i] == 'i')
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
		ft_putchar(format[i]);
		i++;
	}
	return (1);
}

int	main(void)
{
	ft_printf("Une seule string : %s", "Chiasse");
}