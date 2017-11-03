/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_gnl_comment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:22:00 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/21 18:02:11 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_gnl_comment.h"

int		is_gnl_comment(char *gnl, t_mem *mem)
{
	if (ft_strequ(gnl, "##start") == 1)
		return (0);
	if (ft_strequ(gnl, "##end") == 1)
		return (0);
	else if (gnl[0] == '#')
	{
		mem->copy_input = ft_strrjoin(mem->copy_input, gnl);
		if (ft_strequ(gnl, "\n") == FALSE)
			mem->copy_input = ft_strrjoin(mem->copy_input, "\n");
		return (1);
	}
	else
		return (0);
}
