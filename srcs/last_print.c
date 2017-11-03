/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:14:07 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/21 18:10:21 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "last_print.h"

static void		initialize(char **ant, int *is_first_room_is_full, t_mem *mem)
{
	unsigned int	ui;

	ft_bzero(is_first_room_is_full, (mem->count_final_solution) * sizeof(int));
	ui = 0;
	while (ui < mem->number_of_ants)
	{
		ant[ui] = mem->start->name;
		ui++;
	}
}

static void		print_every_moves(char **ant, unsigned int *ui, int *space,
		t_mem *mem)
{
	if ((ant[*ui] != NULL) && (ft_strequ(ant[*ui], mem->start->name) == FALSE))
	{
		if (*space == 1)
			ft_putchar(' ');
		else
			*space = 1;
		ft_putchar('L');
		ft_putunbr(*ui + 1);
		ft_putchar('-');
		ft_putstr(ant[*ui]);
	}
	(*ui)++;
	if (*ui == mem->number_of_ants)
		ft_putchar('\n');
}

static void		modif(t_mem *mem)
{
	char	*double_eol;

	double_eol = ft_strstr(mem->copy_input, "\n\n\n");
	if (double_eol != NULL)
		double_eol[2] = '\0';
}

int				last_print(t_mem *mem)
{
	unsigned int	ui;
	char			*ant[mem->number_of_ants];
	int				is_first_room_is_full[mem->count_final_solution];
	int				space;

	if (mem->final_solution != NULL)
	{
		initialize(ant, is_first_room_is_full, mem);
		modif(mem);
		ft_putstr(mem->copy_input);
		while (ft_strequ(ant[mem->number_of_ants - 1], mem->end->name) == FALSE)
		{
			every_ants_move(ant, is_first_room_is_full, mem);
			ui = 0;
			space = 0;
			while ((ui < mem->number_of_ants) && (mem->start != mem->end))
				print_every_moves(ant, &ui, &space, mem);
		}
	}
	else if (mem->start == mem->end)
		ft_putstr(mem->copy_input);
	else
		return (FAIL);
	return (SUCCESS);
}
