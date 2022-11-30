/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:23:16 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/30 15:23:44 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long long int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	if (num == 0)
		i++;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_d(int num)
{
	int		digit;
	char	*res;
	int		i;
	int		ret;

	digit = ft_count(num);
	res = ft_itoa(num);
	i = 0;
	ret = digit;
	while (digit != 0)
	{
		write(1, &res[i++], 1);
		digit--;
	}
	free(res);
	return (ret);
}
