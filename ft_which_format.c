/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcondemi <bcondemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:33:57 by bcondemi          #+#    #+#             */
/*   Updated: 2025/12/10 13:38:43 by bcondemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_which_format(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_int_to_hex((unsigned long)va_arg(arg, void *), 0, 0));
	if (c == 'd')
		return (ft_putnbr(va_arg(arg, int), 0));
	if (c == 'i')
		return (ft_putnbr(va_arg(arg, int), 0));
	if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(arg, unsigned int), 0));
	if (c == 'x')
		return (ft_int_to_hex(va_arg(arg, unsigned int), 1, 0));
	if (c == 'X')
		return (ft_int_to_hex_maj(va_arg(arg, unsigned int), 1, 0));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
