/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 04:53:52 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/18 14:05:54 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	del_room_content(void *content, size_t len)
{
	t_room	*to_del;

	to_del = (t_room *)content;
	ft_strdel(&to_del->name);
	ft_lstdel(&to_del->adjacent, &ft_simple_del);
	ft_simple_del(content, len);
}

void	del_road(void *content, size_t len)
{
	t_road	*to_del;

	to_del = (t_road *)content;
	ft_lstdel((t_list **)&to_del, &ft_simple_del);
	len = 0;
}
