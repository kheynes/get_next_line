/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:05:40 by kheynes           #+#    #+#             */
/*   Updated: 2019/07/29 10:52:15 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	get_next_line(const int fd, char **line)
{
	static char	*buf;
	int			*r;
	char		*s;

	*buf = NULL;
	if (!line || fd < 0)
		return (-1);
	if (!buf)
		buf = ft_strnew(0);
	r = 1;

}

/*int main()
{
	int		fd;
	//int		n;
	char	*buff;
	char	*store1;
	char	*store2;

	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	store2 = (char *)malloc(sizeof(char) * 1);
	store2[0] = '\0';
	fd = open("test.txt", O_RDONLY);
	while (read(fd, buff, BUFF_SIZE))
	{
		store1 = ft_strnew(BUFF_SIZE);
		buff[BUFF_SIZE + 1] = '\0';
		ft_strncpy(store1, buff, BUFF_SIZE);
		printf("%s", ft_strjoin(store2, store1));
	}
	//s = ft_strnew(BUFF_SIZE);
	//ft_strncpy(s, p, BUFF_SIZE);
	//printf ("%s", s);
	return (0);
}*/
