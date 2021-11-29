/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:08:42 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/29 10:24:41 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//###################### PUTNBR FUNCTIONS ###################### //

int	ft_len(int n)
{
	int	i;

	i = (n < 0);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_len_unsigned(unsigned int n)
{
	int	i;

	i = (n < 0);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

//##################### EXTERNAL FUNCTIONS ##################### //

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(*str)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
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

void	ft_putnbr_base(int nb, char *base)
{
	int long	nbr;

	nbr = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= 16)
		ft_putnbr_base((nbr / 16), base);
	ft_putchar(base[nbr % 16]);
}

void	ft_putunsigned(unsigned int n)
{
	char	c;

	c = n % 10 + '0';
	if (n > 9)
	{
		ft_putunsigned(n / 10);
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}

void	ft_putpointer(unsigned long nb, char *base)
{
	unsigned long	nbr;

	nbr = nb;
	if (nbr >= 16)
		ft_putpointer(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}

// ##################### FLAGS FUNCTIONS ##################### //

int	ft_print_char(va_list formatParams) // For %c
{
	char	c;

	c = (char)va_arg(formatParams, int);
	return (ft_putchar(c));
}

int	ft_print_str(va_list formatParams)
{
	int i;

	if (!((char *)va_arg(formatParams, char *)))
	{
		ft_putstr("(null)");
		return (6);
	}
	i = ft_putstr((char *)va_arg(formatParams, char *));
	return (i);
}
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

// ################### PARSING FUNCTION ################### //

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