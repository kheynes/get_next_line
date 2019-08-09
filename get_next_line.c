/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:05:40 by kheynes           #+#    #+#             */
/*   Updated: 2019/08/09 13:20:42 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*increasebuf(const int fd, char *buf, int *r)
{
	char tmp[BUFF_SIZE + 1];
	char *tmp2;

	*r = read(fd, tmp, BUFF_SIZE);
	if (*r < BUFF_SIZE && tmp[*r - 1] != '\n')
	{
		tmp[*r] = '\n';
		tmp[*r + 1] = '\0';
	}
	else
		tmp[*r] = '\0';
	tmp2 = buf;
	buf = ft_strjoin(buf, tmp);
	ft_strdel(&tmp2);
	return (buf);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf = NULL;
	int			r;
	char		*s;

	if (!line || fd < 0)
		return (-1);
	r = 1;
	if (!buf)
		buf = ft_strnew(0);
	while (r > 0)
	{
		if ((s = ft_strchr(buf, '\n')) != NULL)
		{
			*s = 0;
			*line = ft_strdup(buf);
			ft_memmove(buf, s + 1, ft_strlen(s + 1) + 1);
			return (1);
		}
		buf = increasebuf(fd, buf, &r);
	}
	if (r == 0)
		*line = ft_strnew(0);
	return (r);
}
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl7_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "12345678") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"12345678\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}

