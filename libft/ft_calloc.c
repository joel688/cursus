/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:11:04 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/09 07:56:53 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (size == sizeof(char))
	{
		res = malloc(size * (count + 1));
		if (res == 0)
			return (0);
	}
	res = malloc(size * (count));
	if (res == 0)
		return (0);
	ft_bzero(res, count * size);
	return (res);
}
