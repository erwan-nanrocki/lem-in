/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   every_ants_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:01:36 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/19 13:47:27 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "every_ants_move.h"

static void		a_ant_leave_start(char **ant, int *is_first_room_is_full,
		t_mem *mem, unsigned int ui_ant)
{
	unsigned int	ui_fs;

	ui_fs = 0;
	while ((ui_fs < mem->count_final_solution) &&
			(is_first_room_is_full[ui_fs] != FALSE))
		ui_fs++;
	if (ui_fs < mem->count_final_solution)
	{
		ant[ui_ant] = ((t_road *)
				(mem->final_solution[ui_fs]->content))->next->content;
		is_first_room_is_full[ui_fs] = TRUE;
	}
}

static void		move_a_ant(char **a_ant, int *is_first_room_is_full,
		unsigned int ui_fs, t_mem *mem)
{
	t_road			*temp_road;
	char			*temp_first_room;

	temp_road = ((t_road *)(mem->final_solution[ui_fs]->content))->next;
	temp_first_room = temp_road->content;
	while (temp_road != NULL)
	{
		if (ft_strequ(temp_road->content, *a_ant) == TRUE)
		{
			if (ft_strequ(*a_ant, temp_first_room) == TRUE)
				is_first_room_is_full[ui_fs] = FALSE;
			*a_ant = temp_road->next->content;
			temp_road = NULL;
			ui_fs = mem->count_final_solution;
		}
		else
			temp_road = temp_road->next;
	}
}

static void		can_i_move_this_ant(char **ant, int *is_first_room_is_full,
		t_mem *mem, unsigned int ui_ant)
{
	unsigned int	ui_fs;

	ui_fs = 0;
	if ((ant[ui_ant] != NULL) &&
			(ft_strequ(ant[ui_ant], mem->end->name) == FALSE))
	{
		while (ui_fs < mem->count_final_solution)
		{
			if (ft_strequ(ant[ui_ant], mem->end->name) == FALSE)
				move_a_ant(&(ant[ui_ant]), is_first_room_is_full, ui_fs, mem);
			ui_fs++;
		}
	}
	else
		ant[ui_ant] = NULL;
}

void			every_ants_move(char **ant, int *is_first_room_is_full,
		t_mem *mem)
{
	unsigned int	ui;

	ui = 0;
	while (ui < mem->number_of_ants)
	{
		if (ant[ui] != NULL)
		{
			if (ft_strequ(ant[ui], mem->start->name) == TRUE)
				a_ant_leave_start(ant, is_first_room_is_full, mem, ui);
			else
				can_i_move_this_ant(ant, is_first_room_is_full, mem, ui);
		}
		ui++;
	}
}
