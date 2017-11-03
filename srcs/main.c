/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:01:10 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/25 03:39:57 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		add_gnl_to_mem(t_mem *mem, char *gnl)
{
	if (gnl[0] == 'L')
	{
		ft_strdel(&gnl);
		gnl = ft_strdup("\n");
	}
	else if (mem->progress_status == NUMBER_OF_ANTS)
		add_the_number_of_ants(mem, gnl);
	else
	{
		if (mem->progress_status == ROOM)
			add_a_room(mem, gnl);
		if (mem->progress_status == TUBE)
			add_a_tube(mem, gnl);
	}
	if (mem->progress_status < SEARCH_SOLUTION)
		mem->copy_input = ft_strrjoin(mem->copy_input, gnl);
	if (ft_strequ(gnl, "\n") == FALSE)
		mem->copy_input = ft_strrjoin(mem->copy_input, "\n");
}

static void		initialize(t_mem *mem)
{
	char	*gnl;
	char	r_gnl;

	ft_bzero(mem, sizeof(t_mem));
	mem->copy_input = ft_strdup("");
	r_gnl = 1;
	gnl = ft_strnew(0);
	while ((r_gnl > 0) && ((mem->progress_status == NUMBER_OF_ANTS) ||
				(mem->progress_status == ROOM) ||
				(mem->progress_status == TUBE)))
	{
		ft_strdel(&gnl);
		if ((r_gnl = get_next_line(0, &gnl)) == ERROR)
			mem->progress_status = ERROR;
		else if (is_gnl_comment(gnl, mem) == FALSE)
			add_gnl_to_mem(mem, gnl);
	}
	ft_strdel(&gnl);
	if (mem->progress_status == SEARCH_SOLUTION)
	{
		ft_lstadd(&(mem->research), ft_lstnew(NULL, 0));
		mem->research->content = ft_lstnew(mem->end->name,
				(ft_strlen(mem->end->name) + 1) * sizeof(char));
		mem->research->content_size = sizeof(t_list *);
	}
}

static void		terminate(t_mem *mem)
{
	if (mem != NULL)
	{
		if (mem->room != NULL)
			ft_lstdel(&(mem->room), &del_room_content);
		if (mem->research != NULL)
			ft_lstdel(&(mem->research), &del_road);
		if (mem->solution != NULL)
			ft_lstdel(&(mem->solution), &del_road);
		if (mem->copy_input != NULL)
			ft_strdel(&(mem->copy_input));
	}
}

int				main(int argc, char **argv)
{
	t_mem	mem;

	initialize(&mem);
	option(&mem, argc, argv);
	if (mem.progress_status != ERROR)
		while (mem.progress_status == SEARCH_SOLUTION)
		{
			if (mem.option_p == TRUE)
				print_map(&mem);
			while (mem.progress_status == SEARCH_SOLUTION)
				find_a_road(&mem);
			if (mem.option_p == TRUE)
				print_solution(&mem);
			if (mem.progress_status == JUST_FIND_A_ROAD)
				find_m_road(&mem);
			if (mem.option_p == TRUE)
				print_final_solution(&mem);
		}
	if ((mem.progress_status == ERROR) || (last_print(&mem) == FAIL))
		ft_putendl_fd("ERROR", 2);
	terminate(&mem);
	if (mem.option_l == TRUE)
		leek();
	return (0);
}
