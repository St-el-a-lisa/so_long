/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:07:53 by ecid              #+#    #+#             */
/*   Updated: 2025/04/20 20:27:44 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (start >= ft_strlen(s))
		len = 0;
	else
	{
		if (len > ft_strlen(s + start))
			len = ft_strlen(s + start);
	}
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		substr[j] = s[i + start];
		j++;
		i++;
	}
	substr[j] = '\0';
	return (substr);
}
