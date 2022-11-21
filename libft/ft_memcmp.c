/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:53:09 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/08 12:36:26 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
	{
		if (((unsigned char *)s1)[0] != ((unsigned char *)s2)[0])
			return (((unsigned char *)s1)[0] - ((unsigned char *)s2)[0]);
		s1++;
		s2++;
	}
	return (0);
}
