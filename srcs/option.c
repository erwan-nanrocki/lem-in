/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:59:23 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/19 15:10:16 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"

void			leek(void)
{
	ft_putstr("\033[1;37m");
	ft_putendl("~end : wait for leak test (you can type \"make leaks\")~");
	ft_putstr("~(press [return] to get out)~");
	ft_putendl("\033[m");
	read(1, NULL, 1);
}

static void		corrige_option_m(t_mem *mem)
{
	unsigned int	max_start;
	unsigned int	max_end;
	t_list			*temp_adj;

	max_start = 0;
	temp_adj = mem->start->adjacent;
	while (temp_adj != NULL)
	{
		temp_adj = temp_adj->next;
		max_start++;
	}
	if ((mem->option_m == 0) || (mem->option_m > max_start))
		mem->option_m = max_start;
	max_end = 0;
	temp_adj = mem->end->adjacent;
	while (temp_adj != NULL)
	{
		temp_adj = temp_adj->next;
		max_end++;
	}
	if (mem->option_m > max_end)
		mem->option_m = max_end;
	if (mem->option_m > mem->number_of_ants)
		mem->option_m = mem->number_of_ants;
}

void			option(t_mem *mem, int argc, char **argv)
{
	int		i;

	i = 1;
	mem->option_m = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_strchr(argv[i], 'l') != NULL)
				mem->option_l = TRUE;
			if (ft_strchr(argv[i], 'p') != NULL)
				mem->option_p = TRUE;
			if ((ft_strchr(argv[i], 'm') != NULL) && ((i + 1) < argc))
				mem->option_m = ft_atoui(argv[i + 1]);
			else
				mem->option_m = 1;
			if (mem->progress_status != ERROR)
				corrige_option_m(mem);
		}
		i++;
	}
}
