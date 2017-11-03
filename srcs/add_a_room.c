/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_a_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:25:48 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/19 12:33:20 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_a_room.h"

static int		is_repeat(t_mem *mem)
{
	t_list	*temp_list_1;
	t_list	*temp_list_2;

	temp_list_1 = mem->room;
	while (temp_list_1 != NULL)
	{
		temp_list_2 = temp_list_1->next;
		while (temp_list_2 != NULL)
		{
			if (ft_strequ(((t_room *)(temp_list_2->content))->name,
						((t_room *)temp_list_1->content)->name) == TRUE)
				return (TRUE);
			else if ((((t_room *)(temp_list_2->content))->x ==
						((t_room *)temp_list_1->content)->x) &&
					(((t_room *)(temp_list_2->content))->y ==
						((t_room *)temp_list_1->content)->y))
				return (TRUE);
			else
				temp_list_2 = temp_list_2->next;
		}
		temp_list_1 = temp_list_1->next;
	}
	return (FALSE);
}

static void		define_end_and_start(t_mem *mem)
{
	if (mem->end_def == TO_DEF)
	{
		mem->end = mem->room->content;
		mem->end_def = DEFINED;
	}
	if (mem->start_def == TO_DEF)
	{
		mem->start = mem->room->content;
		mem->start_def = DEFINED;
	}
}

static void		fill_new_room(char *tab_last_str[2], t_room *new_room,
		char *gnl, t_mem *mem)
{
	char			*temp_gnl_0;
	char			*temp_gnl_1;

	if ((ft_is_str_uint(tab_last_str[0]) != TRUE) ||
			(ft_is_str_uint(tab_last_str[0]) != TRUE))
		mem->progress_status = ERROR;
	new_room->x = ft_atoui(tab_last_str[0]);
	new_room->y = ft_atoui(tab_last_str[1]);
	temp_gnl_0 = ft_strrchr(gnl, ' ');
	*temp_gnl_0 = '\0';
	if ((temp_gnl_1 = ft_strrchr(gnl, ' ')) == NULL)
		new_room->name = ft_strdup("");
	else
	{
		*temp_gnl_1 = '\0';
		new_room->name = ft_strdup(gnl);
		*temp_gnl_1 = ' ';
	}
	*temp_gnl_0 = ' ';
	ft_lstadd(&mem->room, ft_lstnew((void *)new_room, sizeof(t_room)));
	if (mem->room->content == NULL)
		mem->progress_status = ERROR;
	define_end_and_start(mem);
	ft_memdel((void **)&new_room);
}

static void		create_new_room(t_mem *mem, char *gnl)
{
	t_room			*new_room;
	unsigned int	ui;
	char			**tab_str;

	tab_str = ft_strsplit(gnl, ' ');
	ui = 0;
	while (tab_str[ui] != NULL)
		ui++;
	if ((ui != 2) && (ui != 3))
	{
		(mem->progress_status)++;
		while (ui > 0)
			ft_strdel(&(tab_str[--ui]));
	}
	else if ((new_room = (t_room *)ft_memalloc(sizeof(t_room))) == NULL)
		mem->progress_status = ERROR;
	else
		fill_new_room(&(tab_str[ui - 2]), new_room, gnl, mem);
	while (ui > 0)
		ft_strdel(&(tab_str[--ui]));
	ft_memdel((void **)&tab_str);
	if (is_repeat(mem) == TRUE)
		mem->progress_status = ERROR;
}

void			add_a_room(t_mem *mem, char *gnl)
{
	if (((mem->start_def == DEFINED) && (ft_strequ(gnl, "##start") == TRUE)) ||
			((mem->end_def == DEFINED) && (ft_strequ(gnl, "##end") == TRUE)))
		mem->progress_status = ERROR;
	else if ((mem->start_def == NOT_DEF) && (ft_strequ(gnl, "##start") == TRUE))
		mem->start_def = TO_DEF;
	else if ((mem->end_def == NOT_DEF) && (ft_strequ(gnl, "##end") == TRUE))
		mem->end_def = TO_DEF;
	else
		create_new_room(mem, gnl);
}
