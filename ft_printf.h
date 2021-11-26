#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int	checkbase(char *str);
void	ft_putnbr_base(int nb, char *base);
void	ft_putunsigned(unsigned int n);
void	ft_print_char(va_list formatParams);
void	ft_print_str(va_list formatParams);
void	ft_print_decimal(va_list formatParams);
void	ft_putnbr_hex(va_list formatParams);
void	ft_print_unsigned(va_list formatParams);
void	ft_parse(va_list formatParams, int i, const char *format);
int	ft_printf(const char *format, ...);


#endif