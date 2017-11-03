/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_the_number_of_ants.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:24:21 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 15:27:54 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_the_number_of_ants.h"

void		add_the_number_of_ants(t_mem *mem, char *gnl)
{
	if (ft_strchr(gnl, '-') != NULL)
		mem->progress_status = ERROR;
	else
	{
		mem->number_of_ants = ft_atoui(gnl);
		if (mem->number_of_ants == 0)
			mem->progress_status = ERROR;
		else
			(mem->progress_status)++;
	}
}
