/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:29:07 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/17 13:58:35 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;
	unsigned long	sol;

	sol = len;
	i = 0;
	if (sol > ft_strlen(s) - start)
		sol = ft_strlen(s) - start;
	if (ft_strlen(s) <= start)
	{
		res = malloc(sizeof(char));
		if (res == 0)
			return (0);
		res[0] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * sol + 1);
	if (res == 0)
		return (0);
	while (i++ < sol)
		*res++ = s[start++];
	*res = '\0';
	return (res - sol);
}
