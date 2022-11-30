/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:50:02 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/30 22:42:39 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_c(int ap);
int		ft_s(char *ap);
int		ft_p(unsigned long long ap);
int		ft_d(int num);
int		ft_countdigit(unsigned long long ap);
int		ft_u(unsigned int ap);
int		ft_x_maj(unsigned int ap);
int		ft_x(unsigned int ap);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
int		ft_write(char *s);

#endif
