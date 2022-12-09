/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:14:03 by joakoeni          #+#    #+#             */
/*   Updated: 2022/12/10 00:24:31 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_isn(char *str)
{
	int	i;

	i = 0;
	while (*str && i <= '\n')
	{
		if (*str == '\n')
			i += *(str);
		str++;
	}
	if (i > '\n')
		return (1);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	int			j;
	char		*line;
	char		*buf;
	static char	*stash = NULL;

	if (fd < 0 || !(BUFFER_SIZE >= 0))
		return (NULL);
	line = NULL;
	j = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	if (stash != NULL)
	{
		line = stash;
		if (ft_isn(line))
		{
			stash = ft_stash(line);
			line = ft_del_after_back_slash_n(line);
			free(buf);
			return (line);
		}
		if (stash[ft_strlen(stash) - 1] == '\n')
		{
			//	free(stash);
			stash = NULL;
			free(buf);
			return (line);
		}
	}
	while (ft_boolean(line) > 0 && j > 0)
	{
		j = read(fd, buf, BUFFER_SIZE);
		buf[j] = '\0';
		line = ft_strjoin(line, buf);
		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
			break ;
		}
		stash = ft_stash(line);
		line = ft_del_after_back_slash_n(line);
	}
	free(buf);
	buf = NULL;
	if (j == -1)
		return (NULL);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("../../francinette/tests/get_next_line/gnlTester/files/41_with_nl",
			O_RDONLY);
while (1)
{
	line = get_next_line(fd);
	if (line == NULL)
		break ;
		printf("%s", line);
	}
}
*/
