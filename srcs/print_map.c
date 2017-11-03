/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 03:03:10 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/19 12:49:43 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_map.h"

static void		print_room(t_mem *mem, t_list *room)
{
	if (room != NULL)
	{
		print_room(mem, room->next);
		if (((t_room *)room->content) == mem->start)
			ft_putendl("##start");
		if (((t_room *)room->content) == mem->end)
			ft_putendl("##end");
		ft_putstr(((t_room *)(room->content))->name);
		ft_putchar(' ');
		ft_putunbr(((t_room *)(room->content))->x);
		ft_putchar(' ');
		ft_putunbr(((t_room *)(room->content))->y);
		ft_putchar('\n');
	}
}

static void		print_tube(t_mem *mem, t_list *room)
{
	t_list	*adj;
	t_list	*temp_room;

	if (room != NULL)
	{
		print_tube(mem, room->next);
		adj = ((t_room *)room->content)->adjacent;
		while (adj != NULL)
		{
			temp_room = mem->room;
			while ((ft_strequ(((t_room *)temp_room->content)->name,
							((t_room *)room->content)->name) == FALSE) &&
					(ft_strequ(((t_room *)temp_room->content)->name,
							((t_room *)adj->content)->name) == FALSE))
				temp_room = temp_room->next;
			ft_putstr(((t_room *)room->content)->name);
			ft_putchar('-');
			ft_putendl(((t_room *)adj->content)->name);
			adj = adj->next;
		}
	}
}

void			print_map(t_mem *mem)
{
	ft_putunbr(mem->number_of_ants);
	ft_putchar('\n');
	print_room(mem, mem->room);
	print_tube(mem, mem->room);
	ft_putchar('\n');
}
