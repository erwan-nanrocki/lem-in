/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_research.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:48:30 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/16 23:29:00 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_research.h"

void	print_research(t_mem *mem)
{
	t_list	*temp_list;
	t_list	*temp_list_list;

	temp_list = mem->research;
	ft_putstr("\n\033[31mR\033[m:");
	if (temp_list == NULL)
		ft_putchar('\n');
	while (temp_list != NULL)
	{
		if (temp_list != mem->research)
			ft_putstr("  ");
		temp_list_list = (t_list *)(temp_list->content);
		while (temp_list_list != NULL)
		{
			ft_putstr(((char *)temp_list_list->content));
			temp_list_list = temp_list_list->next;
			if (temp_list_list != NULL)
				ft_putchar('-');
		}
		ft_putchar('\n');
		temp_list = temp_list->next;
	}
}
