/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:11:58 by joakoeni          #+#    #+#             */
/*   Updated: 2022/12/08 22:18:17 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (42)

# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *line);
char	*ft_strjoin(char *ret, char *buf);
char	*ft_stash(char *res);
char	*ft_del_after_back_slash_n(char *line);
int		ft_boolean(char *line);
int		ft_check_for_stash(char *line);
#endif
