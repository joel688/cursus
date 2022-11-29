/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:20:13 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/29 16:30:35 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	char	*str;
	int		j;

	str = (char *)s;
	va_start(ap, s);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i])
		{
			write(1, &str[i], 1);
			i++;
			j++;
		}
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				j += ft_c(va_arg(ap, int));
			else if (str[i] == 's')
				j += ft_s(va_arg(ap, char *));
			else if (str[i] == 'p')
				j += ft_p(va_arg(ap, unsigned long long));
			else if (str[i] == 'd')
				j += ft_d(va_arg(ap, int));
			else if (str[i] == 'i')
				j += ft_d(va_arg(ap, long long int));
			else if (str[i] == 'u')
				j += ft_u(va_arg(ap, unsigned int));
			else if (str[i] == 'x')
				j += ft_x(va_arg(ap, unsigned int));
			else if (str[i] == 'X')
				j += ft_x_maj(va_arg(ap, unsigned int));
			else if (str[i] == '%')
			{
				write(1, "%", 1);
				j += 1;
			}
			i++;
		}
	}
	va_end(ap);
	return (j);
}

/*int	main(void)
{
	printf("\n%d", ft_printf("%d", -9));
	return (0);
}*/
