/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:54:32 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/30 15:47:03 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int ap)
{
	char	*res;
	int		i;

	res = ft_itoa_unsigned(ap);
	i = ft_s(res);
	free(res);
	return (i);
}
