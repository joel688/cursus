/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:17:29 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/09 11:16:42 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!ft_strlen(needle))
		return (((char *)haystack));
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (0);
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j] && i
			+ j < len)
			j++;
		if (j == ft_strlen(needle))
			return (&((char *)haystack)[i + j - ft_strlen(needle)]);
		i++;
	}
	return (0);
}
