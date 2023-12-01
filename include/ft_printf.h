/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:42:57 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/01 13:33:20 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int		ft_printf(const char *form, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long n);
int		ft_putunbr(unsigned int n);
int		descriptor_check(const char format, va_list args);
int		ft_putnbr_base(unsigned int n, char *base);
int		ft_ctox(unsigned long long str);
int		ft_puthexa(unsigned long long n, char *base);
size_t	ft_strlen(char *s);