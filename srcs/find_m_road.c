/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_m_road.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 11:03:37 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/19 10:52:50 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_m_road.h"

static int		is_repeat(t_list **result, t_mem *mem)
{
	unsigned int	u[2];
	t_road			*temp_road;

	u[0] = 0;
	while (u[0] < mem->count_final_solution + 1)
	{
		u[1] = u[0] + 1;
		while (u[1] < mem->count_final_solution + 1)
		{
			temp_road = result[u[0]]->content;
			while (temp_road != NULL)
			{
				if (ft_strequ(temp_road->content, mem->start->name) == FALSE)
					if (ft_strequ(temp_road->content, mem->end->name) == FALSE)
						if (is_room_in_road(temp_road->content,
									result[u[1]]->content) == TRUE)
							return (TRUE);
				temp_road = temp_road->next;
			}
			u[1]++;
		}
		u[0]++;
	}
	(mem->progress_status)++;
	return (FALSE);
}

static int		next_combinaison(unsigned int *tab, t_mem *mem)
{
	unsigned int	ui;

	ui = 0;
	while (ui < mem->count_final_solution - 1)
		ui++;
	tab[ui]++;
	while (tab[ui] > mem->count_solution - 1)
	{
		ui--;
		tab[ui]++;
	}
	while (ui < mem->count_final_solution - 1)
	{
		ui++;
		tab[ui] = tab[ui - 1] + 1;
	}
	if (tab[ui] >= mem->count_solution - 1)
		return (END);
	return (SUCCESS);
}

static void		fill_result(t_list **result, unsigned int *tab, t_mem *mem)
{
	unsigned int	ui_tab;
	unsigned int	ui_solution;
	t_list			*temp_list;

	ui_tab = 0;
	while (ui_tab < mem->count_final_solution + 1)
	{
		ui_solution = 0;
		temp_list = mem->solution;
		while (ui_solution < tab[ui_tab])
		{
			temp_list = temp_list->next;
			ui_solution++;
		}
		result[ui_tab] = temp_list;
		ui_tab++;
	}
}

static t_list	**initialize(unsigned int *tab, t_mem *mem)
{
	unsigned int	ui;
	t_list			**result;

	ui = 0;
	while (ui < mem->count_final_solution + 1)
	{
		tab[ui] = ui;
		ui++;
	}
	tab[ui - 1] = mem->count_solution - 1;
	result = (t_list **)ft_memalloc((mem->count_final_solution + 1) *
			sizeof(t_list *));
	if (result != NULL)
		fill_result(result, tab, mem);
	return (result);
}

void			find_m_road(t_mem *mem)
{
	unsigned int	tab[mem->count_final_solution + 1];
	t_list			**result;

	if ((result = initialize(tab, mem)) == NULL)
		mem->progress_status = ERROR;
	while ((mem->progress_status == JUST_FIND_A_ROAD) &&
			(is_repeat(result, mem) == TRUE))
	{
		if (next_combinaison(tab, mem) == END)
			(mem->progress_status)--;
		fill_result(result, tab, mem);
	}
	if (mem->progress_status == JUST_FIND_M_ROAD)
	{
		ft_memswap((void **)&mem->final_solution, (void **)&result);
		mem->count_final_solution++;
		if (mem->count_final_solution == mem->option_m)
			mem->progress_status = END;
		else
			mem->progress_status = SEARCH_SOLUTION;
	}
	else if (mem->progress_status == JUST_FIND_A_ROAD)
		mem->progress_status = SEARCH_SOLUTION;
	if (result != NULL)
		ft_memdel((void **)&result);
}
