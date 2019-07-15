/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:05:40 by kheynes           #+#    #+#             */
/*   Updated: 2019/07/15 14:46:06 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h> 
#include <fcntl.h>

int main()
{
	int fd;
	char *p;
	char *s;

	p = (char *)malloc(sizeof(char) *BUFF_SIZE);

	fd = open("test.txt", O_RDONLY);
	read (fd, p, BUFF_SIZE);
	
	s = ft_strnew(BUFF_SIZE);
	ft_strncpy(s, p, BUFF_SIZE);
	printf ("%s", s);
	return (0);
}
