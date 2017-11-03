/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_final_solution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 19:26:59 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/16 23:28:23 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_final_solution.h"

void			print_final_solution(t_mem *mem)
{
	t_road			*temp_road;
	unsigned int	ui;

	ft_putstr("\033[32mF\033[m:");
	ui = 0;
	while (ui < mem->count_final_solution)
	{
		if (ui > 0)
			ft_putstr("  ");
		temp_road = (t_road *)((mem->final_solution[ui])->content);
		while (temp_road != NULL)
		{
			ft_putstr(((char *)temp_road->content));
			temp_road = temp_road->next;
			if (temp_road != NULL)
				ft_putchar('-');
		}
		ft_putchar('\n');
		ui++;
	}
}
