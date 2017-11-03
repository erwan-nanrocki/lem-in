/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room_in_road.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 12:24:02 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/15 12:24:21 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_room_in_road.h"

int		is_room_in_road(char *name, t_road *road)
{
	t_road	*temp_road;

	temp_road = road;
	while (temp_road != NULL)
	{
		if (ft_strequ(name, temp_road->content) == TRUE)
			return (TRUE);
		temp_road = temp_road->next;
	}
	return (FALSE);
}
