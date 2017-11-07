/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:38:17 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/07 14:21:56 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 1024

# define ERROR         -1
# define END_OF_FILE    0
# define END_OF_LINE    1
# define SET_LINE       2
# define I_NEED_TO_READ 3

typedef struct		s_buf
{
	int				fd;
	int				result;
	ssize_t			length;
	char			buf[BUFF_SIZE];
}					t_buf;

int					get_next_line(const int fd, char **line);

#endif
