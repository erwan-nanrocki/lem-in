/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:17:26 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/16 23:28:42 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_solution.h"

void			print_solution(t_mem *mem)
{
	t_list	*temp_list;
	t_road	*temp_road;

	print_research(mem);
	ft_putstr("\033[33mS\033[m:");
	temp_list = mem->solution;
	while (temp_list != NULL)
	{
		if (temp_list != mem->solution)
			ft_putstr("  ");
		temp_road = (t_road *)(temp_list->content);
		while (temp_road != NULL)
		{
			ft_putstr(((char *)temp_road->content));
			temp_road = temp_road->next;
			if (temp_road != NULL)
				ft_putchar('-');
		}
		ft_putchar('\n');
		temp_list = temp_list->next;
	}
}
