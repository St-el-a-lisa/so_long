/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:48:03 by ecid              #+#    #+#             */
/*   Updated: 2025/04/18 16:17:21 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(unsigned long nb, int print)
{
	int	char_count;

	char_count = 0;
	if (!nb)
		return (ft_putstr("(nil)"));
	else if (print)
		char_count += ft_putstr("0x");
	char_count += ft_puthexadecimal_lowerc(nb);
	return (char_count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_puthexadecimal_lowerc(unsigned long nb)
{
	if (nb / 16)
		return (ft_puthexadecimal_lowerc(nb / 16) + ft_puthexadecimal_lowerc(nb
				% 16));
	else if (!(nb / 10))
		ft_putchar(nb + '0');
	else
		ft_putchar((char)nb - 10 + 'a');
	return (1);
}

int	ft_puthexadecimal_upperc(unsigned int nb)
{
	if (nb / 16)
		return (ft_puthexadecimal_upperc(nb / 16) + ft_puthexadecimal_upperc(nb
				% 16));
	else if (!(nb / 10))
		ft_putchar(nb + '0');
	else
		ft_putchar((char)nb - 10 + 'A');
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
