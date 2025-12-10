/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_convertor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:13:33 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/10 13:38:04 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_int_to_hex_maj(unsigned long ptr, int verif, int len)
{
	char			*hexa_base;

	hexa_base = "0123456789ABCDEF";
	if (((void *)ptr == NULL) && ((unsigned long)ptr != 0))
		return (ft_putstr("(nil)"));
	if (verif == 0)
		len += ft_putstr("0x");
	if (ptr > 15)
		len = ft_int_to_hex_maj(ptr / 16, 1, len);
	len += ft_putchar(hexa_base[ptr % 16]);
	return (len);
}

int	ft_int_to_hex(unsigned long ptr, int verif, int len)
{
	char			*hexa_base;

	hexa_base = "0123456789abcdef";
	if (ptr == 0 && verif != 1)
		return (ft_putstr("(nil)"));
	if (verif == 0)
		len += ft_putstr("0x");
	if (ptr > 15)
		len = ft_int_to_hex(ptr / 16, 1, len);
	len += ft_putchar(hexa_base[ptr % 16]);
	return (len);
}

int	ft_putnbr(int n, int len)
{
	if (n == -2147483648)
	{
		len += ft_putstr("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		len += ft_putchar((n % 10 + '0'));
	if (n > 9)
	{
		len = ft_putnbr(n / 10, len);
		len += ft_putchar((n % 10 + '0'));
	}
	return (len);
}

int	ft_unsigned_putnbr(int n, int len)
{
	unsigned int	n2;

	n2 = (unsigned int)n;
	if (n2 < 0)
	{
		len += ft_putchar('-');
		n2 *= -1;
	}
	if (n2 < 10)
		len += ft_putchar((n % 10 + '0'));
	if (n2 > 9)
	{
		len = ft_putnbr(n2 / 10, len);
		len += ft_putchar((n2 % 10 + '0'));
	}
	return (len);
}
