/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:20:13 by joakoeni          #+#    #+#             */
/*   Updated: 2022/12/01 00:11:54 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_j(int j)
{
	if (j < 0)
		return (-1);
	return (j);
}

static void	ft_ifpercent(char *str, int *i, int *j)
{
	int	k;

	k = 0;
	if (str[*i] == '%')
	{
		k = write(1, "%", 1);
		if (k < 0)
			*j += -2147483648;
		*j += 1;
	}
}

static void	ft_ifprintf(char *str, int *i, int *j, va_list ap)
{
	if (str[*i] == '%')
	{
		(*i)++;
		if (str[*i] == 'c')
			*j += ft_c(va_arg(ap, int));
		else if (str[*i] == 's')
			*j += ft_s(va_arg(ap, char *));
		else if (str[*i] == 'p')
			*j += ft_p(va_arg(ap, unsigned long long));
		else if (str[*i] == 'd')
			*j += ft_d(va_arg(ap, int));
		else if (str[*i] == 'i')
			*j += ft_d(va_arg(ap, long long int));
		else if (str[*i] == 'u')
			*j += ft_u(va_arg(ap, unsigned int));
		else if (str[*i] == 'x')
			*j += ft_x(va_arg(ap, unsigned int));
		else if (str[*i] == 'X')
			*j += ft_x_maj(va_arg(ap, unsigned int));
		ft_ifpercent(str, i, j);
		(*i)++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	char	*str;
	int		j;
	int		k;

	str = (char *)s;
	va_start(ap, s);
	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0' && j >= 0 && k >= 0)
	{
		while (str[i] != '%' && str[i])
		{
			k = write(1, &str[i], 1);
			i++;
			j++;
			if (k < 0)
				return (-1);
		}
		ft_ifprintf(str, &i, &j, ap);
	}
	va_end(ap);
	return (ft_j(j));
}
