/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:08:42 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/28 12:01:32 by ngobert          ###   ########.fr       */
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

void	ft_putnbr_hex(va_list formatParams, char *base)
{
	ft_putnbr_base((int)va_arg(formatParams, int), base);
}

int	ft_print_unsigned(va_list formatParams)
{
	int	i;

	i = (unsigned int)va_arg(formatParams, unsigned int);
	ft_putunsigned(i);
	return (ft_len_unsigned(i));
}

void	ft_print_pointer(va_list formatParams)
{
	ft_putstr("0x");
	ft_putpointer((unsigned long)va_arg(formatParams, unsigned long), "0123456789abcdef");
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
	// else if (format[i] == 'p')
	// 	ft_print_pointer(formatParams);
	else if (format[i] == 'd' || format[i] == 'i')
		retVal += ft_print_decimal(formatParams);
	else if (format[i] == 'u')
		retVal += ft_print_unsigned(formatParams);
	// else if (format[i] == 'x')
	// 	retVal += ft_putnbr_hex(formatParams, "0123456789abcdef");
	// else if (format[i] == 'X')
	// 	retVal += ft_putnbr_hex(formatParams, "0123456789ABCDEF");
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
	return (retVal); //!\\ Ne pas oublier la return value (Le nombre de char affichés) !!! write return le nb de char ecrit !! pas mal
}

int	main(void)
{
	int i = printf("%u, %u, %u\n", 12, 42, 56345);
	int j = ft_printf("%u, %u, %u\n", 12, 42, 56345);

	printf("Vrai : %d\nMoi  : %d\n", i, j);
}

// Ya plus qua regler la return value, ET PAS BESOIN DE GERER LES HEXA NEGATIFS