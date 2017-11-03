/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a_road.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 12:35:35 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/19 10:41:52 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_a_road.h"

static void		add_rooms_to_this_road(t_list *temp_adj, t_mem *mem)
{
	t_road		*new_road;

	if (is_room_in_road(((t_room *)(temp_adj->content))->name,
				mem->research->content) == FALSE)
	{
		new_road = ft_lstmap(mem->research->content, &ft_lstdupone);
		ft_lstadd(&new_road,
				ft_lstnew(((t_room *)(temp_adj->content))->name,
					(ft_strlen(((t_room *)(temp_adj->content))->name) + 1)
					* sizeof(char)));
		if (ft_strequ(new_road->content, mem->start->name) == TRUE)
		{
			ft_lstaddend(&mem->solution,
					ft_lstnew(new_road, sizeof(t_road)));
			(mem->progress_status)++;
			(mem->count_solution)++;
		}
		else
		{
			ft_lstaddend(&mem->research,
					ft_lstnew(new_road, sizeof(t_road)));
		}
		ft_memdel((void **)&new_road);
	}
}

void			find_a_road(t_mem *mem)
{
	t_list		*temp_adj;
	t_list		*temp_room;

	if (mem->option_p == TRUE)
		print_research(mem);
	if (mem->research == NULL)
		mem->progress_status = END;
	else
	{
		temp_room = mem->room;
		while (ft_strequ(((t_room *)(temp_room->content))->name,
					((t_list *)(mem->research->content))->content) == FALSE)
			temp_room = temp_room->next;
		temp_adj = ((t_room *)(temp_room->content))->adjacent;
	}
	while ((mem->progress_status == SEARCH_SOLUTION) && (temp_adj != NULL))
	{
		add_rooms_to_this_road(temp_adj, mem);
		temp_adj = temp_adj->next;
	}
	ft_lstdelhead(&mem->research, &del_road);
}
