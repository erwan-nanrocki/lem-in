/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_a_tube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:40:01 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/19 10:45:05 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_a_tube.h"

static int	add_one_tube(t_mem *mem, char *name1, char *name2)
{
	t_list	*temp_room_1;
	t_list	*temp_room_2;

	temp_room_1 = mem->room;
	while ((temp_room_1 != NULL) &&
			(ft_strequ(((t_room *)temp_room_1->content)->name, name1) == FALSE))
		temp_room_1 = temp_room_1->next;
	temp_room_2 = mem->room;
	while ((temp_room_2 != NULL) &&
			(ft_strequ(((t_room *)temp_room_2->content)->name, name2) == FALSE))
		temp_room_2 = temp_room_2->next;
	if ((temp_room_1 == NULL) || (temp_room_2 == NULL))
	{
		(mem->progress_status)++;
		return (SUCCESS);
	}
	ft_lstadd(&(((t_room *)temp_room_1->content)->adjacent),
			ft_lstnew((void *)(temp_room_2->content), sizeof(t_room *)));
	ft_lstadd(&(((t_room *)temp_room_2->content)->adjacent),
			ft_lstnew((void *)(temp_room_1->content), sizeof(t_room *)));
	if ((((t_room *)temp_room_1->content)->adjacent->content == NULL) &&
			(((t_room *)temp_room_2->content)->adjacent->content == NULL))
		return (ERROR);
	return (SUCCESS);
}

void		add_a_tube(t_mem *mem, char *gnl)
{
	unsigned int	ui;
	unsigned int	ui_minus;

	if ((mem->start_def != DEFINED) || (mem->end_def != DEFINED))
		mem->progress_status = ERROR;
	else
	{
		ui = 0 - 1;
		ui_minus = 0;
		while ((gnl[++ui] != '\0') && (mem->progress_status == TUBE))
			if ((gnl[ui] == '-') && (ui_minus > 0))
				(mem->progress_status)++;
			else if (gnl[ui] == '-')
				ui_minus = ui;
		if (gnl[ui_minus] != '-')
			(mem->progress_status)++;
		gnl[ui_minus] = '\0';
		if (mem->progress_status == TUBE)
		{
			if (add_one_tube(mem, &(gnl[0]), &(gnl[ui_minus + 1])) == ERROR)
				mem->progress_status = ERROR;
			gnl[ui_minus] = '-';
		}
	}
}
