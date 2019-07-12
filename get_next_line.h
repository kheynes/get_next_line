/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:51:01 by kheynes           #+#    #+#             */
/*   Updated: 2019/07/12 10:28:15 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft/libft.h"

typedef struct	s_gnl
{
	int				fd;
	char			*line;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(const int fd, char **line);
#endif
