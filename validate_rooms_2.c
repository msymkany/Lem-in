/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rooms_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:51:34 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/08 19:51:51 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		get_room_num(t_map *map)
{
	t_room		*ptr;

	if (map->rooms->next == NULL)
		map->rooms->num = 0;
	else
	{
//		ptr = map->rooms;
		map->rooms->num = ++map->rooms->next->num;
	}

}

static void		check_command_2(char **line, t_map *map, t_input **in)
{
	push_to_input(in, *line);
	ft_strdel(line);
	get_next_line(0, line);
	if (*line[0] == '#')
		ft_error();
	else
	{
		check_room_format(map, *line);
		get_room_num(map);
	}
}

void		check_command(char **line, t_map *map, t_input **in)
{
	if (ft_strequ(*line, "##start"))
	{
		check_command_2(line, map, in);
		map->start = map->rooms->num;
	}
	else if (ft_strequ(*line, "##end"))
	{
		check_command_2(line, map, in);
		map->end = map->rooms->num;
	}
}

void 	validate_room_coordinates(t_map *map)
{
	t_room		*ptr;

	if (map->rooms->next)
	{
		ptr = map->rooms;
		while ((ptr = ptr->next))
		{
			if (map->rooms->x == ptr->x && map->rooms->y == ptr->y)
				ft_error();
		}
	}
}

void 	check_room_name_dub(t_map *map)
{
	t_room		*ptr;

	if (map->rooms->next)
	{
		ptr = map->rooms;
		while ((ptr = ptr->next))
		{
			if (ft_strequ(map->rooms->name, ptr->name))
				ft_error();
		}
	}
}

//void		check_command(char **line, t_map *map, t_input **in)
//{
//	if (ft_strequ(*line, "##start"))
//	{
//		push_to_input(in, *line);
//		ft_strdel(line);
//		get_next_line(0, line);
//		if (*line[0] == '#')
//			ft_error();
//		else
//		{
//			check_room_format(map, *line);
//			map->start = map->rooms->num; // get_room_num(map);
//		}
//	}
//	else if (ft_strequ(*line, "##end"))
//	{
//		push_to_input(in, *line);
//		ft_strdel(line);
//		get_next_line(0, line);
//		if (*line[0] == '#')
//			ft_error();
//		else
//		{
//			check_room_format(map, *line);
//			map->end = map->rooms->num;
//		}
//	}
//}
