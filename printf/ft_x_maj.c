/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_maj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:21:57 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/29 17:44:41 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countdigit1(unsigned long long ap)
{
	int	len;

	len = 0;
	if (ap == 0)
		len++;
	while (ap > 0)
	{
		ap /= 16;
		len++;
	}
	return (len);
}

int	ft_x_maj(unsigned int ap)
{
	unsigned int	adrr;
	char			*base;
	char			*res;
	int				i;
	int				j;

	base = "0123456789ABCDEF";
	i = ft_countdigit1(ap);
	res = malloc(sizeof(char) * i + 1);
	if (res == NULL)
		return (-1);
	res[i] = '\0';
	j = i;
	while (ap > 0)
	{
		adrr = ap % 16;
		ap /= 16;
		res[--i] = base[adrr];
	}
	ft_s(res);
	free(res);
	return (j);
}
