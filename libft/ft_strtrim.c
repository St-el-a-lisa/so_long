/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecid <ecid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:07:53 by ecid              #+#    #+#             */
/*   Updated: 2025/04/20 20:09:41 by ecid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	starting;
	size_t	ending;

	if (!s1 || !set)
		return (NULL);
	starting = 0;
	while (s1[starting] && ft_in_set(s1[starting], set))
		starting++;
	ending = ft_strlen(s1);
	while (ending > starting && ft_in_set(s1[ending - 1], set))
		ending--;
	return (ft_substr(s1, starting, ending - starting));
}
