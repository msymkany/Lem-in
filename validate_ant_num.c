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
		ft_error("##start in ant num section");
	if (ft_strequ(line, "##end"))
		ft_error("##end in ant num section");
}

void	get_n_ants(char *line, t_map *map)
{
	size_t	i;

	i = 0;
	if (ft_isalpha(line[0]))
		ft_error("wrong comment format");
	i = ft_extract_digits(&(map)->ants_num, line, i);
	if (!(map)->ants_num)
		ft_error("wrong number of ants");
	if (line[i])
		ft_error("wrong format of ants number");
}

void		validate_ant_num(t_input **in, t_map *map)
{
	char 		*line;

	line = NULL;
	while (!map->ants_num && get_next_line(0, &line))
	{
		if (!line)
			ft_error("empty line");
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
	if (!*in)
		ft_error("empty file");


//	write(1, "OK ants num\n", 12); // test
//	ft_printf("%d\n", map->ants_num); // test
//	print_input(*in);  // test
}
