/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:39:09 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/06 18:24:35 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*add_fd_to_mem(t_list **mem, int new_fd)
{
	t_buf	new_buf;
	t_list	*new_head;

	new_buf.fd = new_fd;
	new_buf.result = I_NEED_TO_READ;
	new_buf.length = 0;
	new_buf.buf[0] = '\0';
	new_head = ft_lstnew(&new_buf, sizeof(t_buf));
	if (new_head == NULL)
		return (NULL);
	else if (new_head->content == NULL)
	{
		ft_lstdelone(&new_head, &ft_simple_del);
		return (NULL);
	}
	ft_lstadd(mem, new_head);
	return (*mem);
}

static t_list		*initialize(char **line, t_list **mem, int fd)
{
	t_list			*current_buf;

	current_buf = *mem;
	*line = ft_strnew(0);
	while ((current_buf != NULL) &&
			(((t_buf *)(current_buf->content))->fd != fd))
		current_buf = current_buf->next;
	if (current_buf == NULL)
		current_buf = add_fd_to_mem(mem, fd);
	if (current_buf == NULL)
		((t_buf *)(current_buf->content))->result = ERROR;
	return (current_buf);
}

static void			set_line(char **line, t_buf *src_buf)
{
	char	*next;
	char	*temp_line;

	if (src_buf->result != ERROR)
	{
		if ((next = ft_strnchr(src_buf->buf, '\n', src_buf->length)) == NULL)
			next = src_buf->buf + src_buf->length;
		else
		{
			next++;
			src_buf->result = END_OF_LINE;
		}
		temp_line = ft_strnnjoin(*line, src_buf->buf,
				ft_strlen(*line), (size_t)(next - src_buf->buf));
		ft_memmove(src_buf->buf, next,
				src_buf->length -= ft_strlen(temp_line) - ft_strlen(*line));
		ft_strdel(line);
		*line = temp_line;
	}
}

static void			terminate(char **line, t_buf *current_buf)
{
	if ((*line)[ft_strlen(*line) - 1] == '\n')
		(*line)[ft_strlen(*line) - 1] = '\0';
	if ((current_buf->result == END_OF_FILE) && ((*line)[0] != '\0'))
		current_buf->result = END_OF_LINE;
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*mem = NULL;
	t_list			*current_buf;

	if ((fd < 0) || (line == NULL))
		return (ERROR);
	current_buf = initialize(line, &mem, fd);
	((t_buf *)(current_buf->content))->result = SET_LINE;
	while (((t_buf *)(current_buf->content))->result == SET_LINE)
	{
		if (((t_buf *)(current_buf->content))->length == 0)
		{
			((t_buf *)(current_buf->content))->length =
				read(fd, ((t_buf *)(current_buf->content))->buf, BUFF_SIZE);
			if (((t_buf *)(current_buf->content))->length <= -1)
				((t_buf *)(current_buf->content))->result = ERROR;
			else if (((t_buf *)(current_buf->content))->length == 0)
				((t_buf *)(current_buf->content))->result = END_OF_FILE;
			else
				((t_buf *)(current_buf->content))->result = SET_LINE;
		}
		set_line(line, ((t_buf *)(current_buf->content)));
	}
	terminate(line, ((t_buf *)(current_buf->content)));
	return (((t_buf *)(current_buf->content))->result);
}
