/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:15:14 by ngobert           #+#    #+#             */
/*   Updated: 2021/11/29 12:44:21 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
