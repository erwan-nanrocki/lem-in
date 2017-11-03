/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:38:17 by enanrock          #+#    #+#             */
/*   Updated: 2017/09/17 18:31:12 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 1024

typedef struct		s_content
{
	int				fd;
	ssize_t			len;
	char			buf[BUFF_SIZE];
}					t_content;

typedef struct		s_buf
{
	t_content		*content;
	size_t			content_size;
	struct s_buf	*next;
}					t_buf;

int					get_next_line(const int fd, char **line);

#endif
