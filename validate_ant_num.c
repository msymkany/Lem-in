/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ant_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 17:36:31 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/06 17:36:35 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_command_in_wrong_block(char *line)
{
	if (ft_strequ(line, "##start"))
		ft_error();
	if (ft_strequ(line, "##end"))
		ft_error();
}

void	get_n_ants(char *line, t_map *map)
{
	size_t	i;

	i = 0;
	i = ft_extract_digits(&(map)->ants_num, line, i);
	if (!(map)->ants_num)
		ft_error();
	if (line[i])
		ft_error();
}

void		validate_ant_num(t_input **in, t_map *map)
{
	char 		*line;

	line = NULL;
	while (!map->ants_num && get_next_line(0, &line))
	{
		if (!line)
			ft_error();
		else if (line[0] == '#')
		{
			check_command_in_wrong_block(line);
			push_to_input(in, line);
		}
		else
		{
			get_n_ants(line, map);
			push_to_input(in, line);
		}
		ft_strdel(&line);
	}
	write(1, "OK ants num\n", 3); // test
	ft_printf("%d\n", map->ants_num); // test
	print_input(*in);  // test
}
