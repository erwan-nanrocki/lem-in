/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:39:09 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/02 20:59:35 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buf		*init_lst_buf(int fd, t_buf **lst_buf)
{
	t_content	*tmp_content;
	t_buf		*result;

	if (*lst_buf == NULL)
	{
		if ((tmp_content = (t_content *)malloc(sizeof(t_content))) == NULL)
			return (NULL);
		tmp_content->fd = fd;
		if ((tmp_content->len = read(fd, tmp_content->buf, BUFF_SIZE)) == -1)
		{
			free(tmp_content);
			return (NULL);
		}
		result = (t_buf *)ft_lstnew(tmp_content, sizeof(t_content));
		free(tmp_content);
	}
	else
		result = *lst_buf;
	return (result);
}

static t_content	*init(char **line, size_t *len_line,
		t_buf **lst_buf, int fd)
{
	t_buf	*temp_buf;

	if ((line == NULL) || ((*lst_buf = init_lst_buf(fd, lst_buf)) == NULL))
		return (NULL);
	temp_buf = *lst_buf;
	if ((*line = (char *)malloc(1 * sizeof(char))) == NULL)
		return (NULL);
	(*line)[0] = '\0';
	*len_line = 0;
	while ((temp_buf->next != NULL) && (temp_buf->content->fd != fd))
		temp_buf = temp_buf->next;
	if (temp_buf->content->fd == fd)
		return (temp_buf->content);
	if ((temp_buf->next = (t_buf *)malloc(sizeof(t_buf))) == NULL)
		return (NULL);
	if ((temp_buf->next->content =
				(t_content *)malloc(sizeof(t_content))) == NULL)
		return (NULL);
	temp_buf->next->content_size = sizeof(t_content);
	temp_buf->next->content->fd = fd;
	temp_buf->next->next = NULL;
	if ((temp_buf->next->content->len =
				read(fd, temp_buf->next->content->buf, BUFF_SIZE)) == -1)
		return (NULL);
	return (temp_buf->next->content);
}

static void			ralloc_nnjoin(char **line, size_t *len_line,
		char *buf, ssize_t len_buf)
{
	char	*temp_line;

	temp_line = ft_strnnjoin(*line, buf, *len_line, len_buf);
	*len_line += len_buf;
	free(*line);
	*line = temp_line;
}

int					get_next_line(const int fd, char **line)
{
	size_t			len_line;
	t_content		*c_buf;
	char			*temp_str;
	static t_buf	*lst_buf = NULL;

	if ((fd < 0) || ((c_buf = init(line, &len_line, &lst_buf, fd)) == NULL))
		return (-1);
	if (c_buf->len == 0)
		if ((c_buf->len = read(c_buf->fd, c_buf->buf, BUFF_SIZE)) == -1)
			return (-1);
	while (c_buf->len > 0)
		if ((temp_str = ft_strnchr(c_buf->buf, '\n', c_buf->len)) == NULL)
		{
			ralloc_nnjoin(line, &len_line, c_buf->buf, c_buf->len);
			if ((c_buf->len = read(c_buf->fd, c_buf->buf, BUFF_SIZE)) == -1)
				return (-1);
		}
		else
		{
			ralloc_nnjoin(line, &len_line, c_buf->buf, temp_str - c_buf->buf);
			ft_memmove(c_buf->buf, temp_str + 1,
					c_buf->len = c_buf->len - (temp_str - c_buf->buf + 1));
			return (1);
		}
	return (((*line)[0] == '\0') ? 0 : 1);
}
/*
**  #include <fcntl.h>
**  #include <stdio.h>
**  int					main(void)
**  {
**  	int		fd1;
**  	int		fd2;
**  	int		fd3;
**  	char	*line;
**  	int		result;
**  	int		i;
**  	int		i1;
**  	int		i2;
**  	fd1 = open("a1.txt", O_RDONLY);
**  	fd2 = open("a2.txt", O_RDONLY);
**  	fd3 = open("a3.txt", O_RDONLY);
**  	printf("\n""fd1 = %d""\n""fd2 = %d""\n", fd1, fd2);
**  	printf("BUFF_SIZE = %d""\n", BUFF_SIZE);
**  	i = 0;
**  	i1 = 1;
**  	i2 = 1;
**  	while (i++ < 5)
**  	{
**  		{
**  			printf("\033[m""fd = %d""\n", fd1);
**  			result = get_next_line(fd1, &line);
**  			printf("\033[1;36m");
**  			printf("result of get_next_line n*%d == %d""\033[m\n",
**  					i1++, result);
**  			if (line != NULL)
**  			{
**  				ft_putstr("\033[1;32m""line = \"""\033[1;35m");
**  				ft_putstr(line);
**  				ft_putstr("\033[1;32m""\"""\n");
**  				free(line);
**  			}
**  		}
**  		printf("\n");
**  		{
**  			printf("\033[m""fd = %d""\n", fd1);
**  			result = get_next_line(fd1, &line);
**  			printf("\033[1;36m");
**  			printf("result of get_next_line n*%d == %d""\033[m\n",
**  					i1++, result);
**  			if (line != NULL)
**  			{
**  				ft_putstr("\033[1;32m""line = \"""\033[1;35m");
**  				ft_putstr(line);
**  				ft_putstr("\033[1;32m""\"""\n");
**  				free(line);
**  			}
**  		}
**  		printf("\n");
**  		{
**  			ft_putstr("                                     ");
**  			printf("\033[0;37;7m""fd = %d""\033[m""\n", fd2);
**  			result = get_next_line(fd2, &line);
**  			ft_putstr("                                     ");
**  			printf("\033[1;36;7m");
**  			printf("result of get_next_line n*%d == %d""\033[0;37m\n",
**  					i2++, result);
**  			if (line != NULL)
**  			{
**  				ft_putstr("                                     ");
**  				ft_putstr("\033[1;32;7m""line = \"""\033[1;35;7m");
**  				ft_putstr(line);
**  				ft_putstr("\033[1;32;7m""\"""\n");
**  				free(line);
**  			}
**  		}
**  	}
**  return (0);
**  }
*/
