/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:48:56 by dydado13          #+#    #+#             */
/*   Updated: 2023/12/01 13:31:57 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

// size_t	ft_strlen(char *s)
// {
// 	int	j;

// 	j = 0;
// 	while (s[j])
// 		j++;
// 	return (j);
// }

int	ft_putstr(char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		ft_putchar('-');
		i += ft_putnbr(n * (-1));
	}
	else if (n >= 0 && n < 10)
	{
		i++;
		ft_putchar(n + 48);
	}
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int	ft_putnbr_base(unsigned int n, char *base)
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
		i += ft_putnbr_base(n / 16, base);
		i += ft_putnbr_base(n % 16, base);
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
