/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:48:03 by ecid              #+#    #+#             */
/*   Updated: 2025/04/18 16:21:00 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_nb(long nb)
{
	char	buffer[20];
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	if (nb == 0)
		buffer[i++] = '0';
	while (nb > 0)
	{
		buffer[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (--i >= 0)
		count += ft_putchar(buffer[i]);
	return (count);
}

size_t	ft_putnbr(const int n)
{
	long	nb;
	size_t	count;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	count += print_nb(nb);
	return (count);
}

int	ft_putunbr(unsigned int nb)
{
	if (nb / 10)
		return (ft_putunbr(nb / 10) + ft_putunbr(nb % 10));
	return (ft_putchar(nb + '0'));
}
