/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:59:16 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/11 16:57:52 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;
	int	b;

	i = ft_strlen(((char *)s));
	j = 0;
	b = 0;
	if (((char)c) == '\0')
		return (((char *)s) + ft_strlen((char *)s));
	while (b++ != i)
		s++;
	while (((char)c) != s[0] && j++ < i)
		s--;
	if (s[0] == '\0' && c != '\0')
		return (0);
	if (((char)c) == s[0])
		return (((char *)s));
	return (0);
}
