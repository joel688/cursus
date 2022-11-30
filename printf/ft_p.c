/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:23:12 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/30 23:58:26 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p(unsigned long long ap)
{
	unsigned int	adrr;
	char			*base;
	char			*res;
	int				len;

	adrr = 0;
	base = "0123456789abcdef";
	len = ft_countdigit(ap);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (-2147483648);
	res[len] = '\0';
	while (len > 2)
	{
		adrr = ap % 16;
		ap /= 16;
		res[--len] = base[adrr];
	}
	res[0] = '0';
	res[1] = 'x';
	len = ft_write(res);
	free(res);
	return (len);
}
