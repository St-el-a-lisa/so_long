/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:08:34 by ecid              #+#    #+#             */
/*   Updated: 2024/12/07 19:33:05 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(va_list args, const char specifier)
{
	int	i;

	i = 0;
	if (specifier == 'c')
		i += ft_putchar((char)va_arg(args, int));
	else if (specifier == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		i += ft_putadress(va_arg(args, unsigned long), 1);
	else if (specifier == 'd' || specifier == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		i += ft_putunbr(va_arg(args, unsigned int));
	else if (specifier == 'x')
		i += ft_puthexadecimal_lowerc(va_arg(args, unsigned int));
	else if (specifier == 'X')
		i += ft_puthexadecimal_upperc(va_arg(args, unsigned int));
	else if (specifier == '%')
		i += ft_putchar(('%'));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			char_count += check_type(args, format[i + 1]);
			i++;
		}
		else
			char_count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (char_count);
}
