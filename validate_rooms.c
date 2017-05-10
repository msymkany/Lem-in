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

static int 		check_spaces(char *line)
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

static size_t		get_room_name(char *line, t_map *map)
{
	size_t		j;

	j = 0;
	push_to_room(&map->rooms);
	while (line[j] && !map->rooms->name)
	{
		if (line[j] == ' ')
		{
			map->rooms->name = ft_strsub(line, 0, j);
			break ;
		}
		else if (line[j] == '-' || line[j] == ' ')
			ft_error("wrong format of room name");
		j++;
	}
	return (j);
}

void		check_room_format(t_map *map, char *line)
{
	size_t		j;

	j = 0;
	if (check_spaces(line) && line[0] != 'L')
		j = get_room_name(line, map);
	else
		ft_error("wrong format of room name");
	if (line[j] == ' ')
	{
		if (!(j = ft_extract_digits(&map->rooms->x, line, ++j)))
			ft_error("wrong format of room coordinates");
	}
	else
		ft_error("wrong format of room coordinates");
	if (line[j] == ' ')
	{
		if (!(j = ft_extract_digits(&map->rooms->y, line, ++j)))
			ft_error("wrong format of room coordinates");
	}
	else
		ft_error("wrong format of room coordinates");
	if (line[j] != 0)
		ft_error("wrong format of room coordinates");
}

void		validate_rooms(t_input **in, t_map *map)
{
	char 	*line;

	line = NULL;
	while (get_next_line(0, &line) && (line[0] == '#' || check_spaces(line)))
	{
		if (line[0] == '#' && line[1] == '#')
		{
			check_command(&line, map, in);
			push_to_input(in, line);
		}
		else
		{
			check_room_format(map, line);
			push_to_input(in, line);
		}
		if (map->rooms && map->rooms->next)
		{
			check_room_name_dub(map);
			validate_room_coordinates(map);
		}
		ft_strdel(&line);
	}
	if (!*line)
		ft_error("empty line");
	if (!map->rooms)
		ft_error("no rooms");
	if (map->start == -1 || map->end == -1)
		ft_error("no start or end room");
	push_to_input(in, line); // last one goes to links
	ft_strdel(&line);
	write(1, "OK room\n", 8); // test
	ft_printf("%d\n", map->start); // test
	ft_printf("%d\n", map->end); // test
	print_input(*in);  // test
}
