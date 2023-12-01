/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:51 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/01 13:27:55 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthexa(unsigned long long n, char *base)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		i++;
		ft_putchar(base[n % 16]);
	}
	else
	{
		i += ft_puthexa(n / 16, base);
		i += ft_puthexa(n % 16, base);
	}
	return (i);
}

int	ft_ctox(unsigned long long str)
{
	int	i;

	if (!str)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = 2;
	write(1, "0x", 2);
	i += ft_puthexa(str, "0123456789abcdef");
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putunbr(n / 10);
		i += ft_putunbr(n % 10);
	}
	else
	{
		i++;
		ft_putchar(n + 48);
	}
	return (i);
}

int	descriptor_check(const char format, va_list args)
{
	int		i;

	i = 0;
	if (format == '%')
		i += ft_putchar('%');
	else if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'x')
		i += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		i += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'u')
		i += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'p')
		i += ft_ctox(va_arg(args, unsigned long long));
	return (i);
}
