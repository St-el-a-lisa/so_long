/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:22:43 by ecid              #+#    #+#             */
/*   Updated: 2024/12/08 15:33:06 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_putchar(char c);
size_t	ft_putnbr(const int n);
int		ft_putstr(char *str);
int		check_type(va_list args, const char specifier);
int		ft_putunbr(unsigned int nb);
int		ft_puthexadecimal_lowerc(unsigned long nb);
int		ft_puthexadecimal_upperc(unsigned int nb);
int		ft_putadress(unsigned long nb, int print);
int		ft_printf(const char *format, ...);

#endif
