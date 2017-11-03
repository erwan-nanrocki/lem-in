/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:10:12 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/19 12:37:51 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

# define TRUE             1
# define FALSE            0

# define SUCCESS          1
# define FAIL             0

# define ERROR           -1
# define NUMBER_OF_ANTS   0
# define ROOM             1
# define TUBE             2
# define SEARCH_SOLUTION  3
# define JUST_FIND_A_ROAD 4
# define JUST_FIND_M_ROAD 5
# define END              6

# define NOT_DEF          0
# define TO_DEF           1
# define DEFINED          2

typedef	t_list		t_road;

typedef	struct		s_room
{
	char			*name;
	unsigned int	x;
	unsigned int	y;
	t_list			*adjacent;
}					t_room;

typedef	struct		s_mem
{
	char			*copy_input;
	int				progress_status;
	unsigned int	number_of_ants;
	t_room			*start;
	int				start_def;
	t_room			*end;
	int				end_def;
	t_list			*room;
	t_list			*research;
	t_list			*solution;
	unsigned int	count_solution;
	t_list			**final_solution;
	unsigned int	count_final_solution;
	int				option_s;
	int				option_l;
	int				option_p;
	unsigned int	option_m;
}					t_mem;

void				del_room_content(void *content, size_t size);
void				del_road(void *content, size_t len);

#endif
