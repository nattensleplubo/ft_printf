/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:09:14 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/26 13:58:32 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//###################### PUTNBR FUNCTIONS ###################### //

static int	ft_len(int n)
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
	while(str[i])
	{
		write(1, str[i], 1);
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

int	checkbase(char *str) // FOR PUTNBR BASE
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		if ((str[i] > 06 && str[i] < 14) || str[i] == 32)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nb, char *base)
{
	int			j;
	int long	nbr;

	j = 0;
	nbr = nb;
	if (checkbase(base) == 0)
		return ;
	j = checkbase(base);
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= j)
		ft_putnbr_base((nbr / j), base);
	ft_putchar(base[nbr % j]);
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
	ft_putchar(c);
	return (1);
}

int	ft_print_str(va_list formatParams)
{
	return (ft_putstr((char *)va_arg(formatParams, char *)));
}

void	ft_print_decimal(va_list formatParams)
{
	ft_putnbr((int)va_arg(formatParams, int));
}

void	ft_putnbr_hex(va_list formatParams)
{
	ft_putnbr_base((int)va_arg(formatParams, int), "0123456789abcdef");
}

void	ft_print_unsigned(va_list formatParams)
{
	ft_putunsigned((unsigned int)va_arg(formatParams, unsigned int));
}

void	ft_print_pointer(va_list formatParams)
{
	ft_putstr("0x");
	ft_putpointer((unsigned long)va_arg(formatParams, unsigned long), "0123456789abcdef");
}

// ################### PARSING FUNCTION ################### //

void	ft_parse(va_list formatParams, int i, const char *format)
{
	i++;
	if (format[i] == 'c')
		ft_print_char(formatParams);
	else if (format[i] == 's')
		ft_print_str(formatParams);
	else if (format[i] == 'p')
		ft_print_pointer(formatParams);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_decimal(formatParams);
	else if (format[i] == 'u')
		ft_print_unsigned(formatParams);
	else if (format[i] == 'x')
		ft_putnbr_hex(formatParams);
	else if (format[i] == '%')
		ft_putchar('%');
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
	return (1); //!\\ Ne pas oublier la return value (Le nombre de char affichés) !!! write return le nb de char ecrit !! pas mal
}

int	main(void)
{
	int i = 0;
	printf("%d, %p\n", i, NULL);
	ft_printf("%d, %p\n", i, NULL);
}

// Ya plus qua regler la return value !