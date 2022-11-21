/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:42:53 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/10 11:36:45 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = ft_strlen(((char *)s));
	j = 0;
	if (((char)c) == '\0')
		return (((char *)s) + ft_strlen((char *)s));
	while (((char)c) != s[0] && j++ < i)
		s++;
	if (s[0] == '\0' && c != '\0')
		return (0);
	if (((char)c) == s[0])
		return (((char *)s));
	return (0);
}
