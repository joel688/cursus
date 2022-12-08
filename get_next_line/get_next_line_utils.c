/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:58:21 by joakoeni          #+#    #+#             */
/*   Updated: 2022/12/08 18:53:14 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_for_stash(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_boolean(char *line)
{
	if (line == NULL)
		return (1);
	if (line[ft_strlen(line) - 1] == '\n')
		return (0);
	return (1);
}

char	*ft_del_after_back_slash_n(char *line)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		line[i + 1] = '\0';
	return (line);
}

char	*ft_stash(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (line == NULL)
		return (NULL);
	if (ft_check_for_stash(line) == 0)
		return (NULL);
	while (line[i] != '\n')
		i++;
	i++;
	tmp = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (tmp == NULL)
		return (NULL);
	while (line[i] != '\0')
	{
		tmp[j] = line[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

size_t	ft_strlen(char *line)
{
	size_t	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*linejoined;
	size_t	len;
	int		i;
	size_t r;

	i = 0;
	r = ft_strlen(line);
	len = ft_strlen(line) + ft_strlen(buf);
	linejoined = malloc(sizeof(char) * len + 1);
	if (linejoined == NULL)
		return (NULL);
	if (line != NULL)
		while (*line != '\0')
			*linejoined++ = *line++;
	while (buf[i] != '\0')
		*linejoined++ = *buf++;
	*linejoined = '\0';
	//if(line != NULL)
	//	free(line - r);
	return (linejoined - len);
}
