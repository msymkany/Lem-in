/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 17:43:51 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/06 17:43:55 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 		check_spaces(char *line)
{
	int 	i;

	i = 0;
	while (*line)
	{
		if (*line == ' ')
			i++;
		line++;
	}
	if (i == 2)
		return (1);
	return (0);
}

void		check_command(char *line, t_map *map)
{

}

void		validate_rooms(t_input **in, t_map *map)
{
	char 	*line;

	line = NULL;
	while (get_next_line(0, &line) && (line[0] == '#' || check_spaces(line)))
	{
		if (line[0] == '#' && line[1] == '#')
		{
			check_command(line, map);
			push_to_input(in, line);
		}
//		else
//		{
//			push_to_input(in, line);
//		}
		ft_strdel(&line);
	}
	write(1, "OK room\n", 8); // test
//	ft_printf("%d\n", map->ants_num); // test
//	print_input(*in);  // test
}
