/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:12:16 by ecid              #+#    #+#             */
/*   Updated: 2025/04/23 21:22:19 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*is_over(char *str, long int n)
{
	int	len;
	int	temp_len;

	len = count_len(n);
	temp_len = len;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[temp_len] = '\0';
	return (str);
}

static char	*is_under(char *str, long int n)
{
	int	len;
	int	temp_len;

	n = n * -1;
	len = count_len(n);
	temp_len = len;
	str = malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	while (len > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[temp_len + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;

	nb = n;
	str = NULL;
	if (nb == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	else if (nb > 0)
		str = is_over(str, nb);
	else
		str = is_under(str, nb);
	return (str);
}
