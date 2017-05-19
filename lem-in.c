/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:10:34 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/28 17:10:42 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		read_input(t_input **in, t_map *map)
{
	validate_ant_num(in, map);
	validate_rooms(in, map);
	validate_links(in, map);
}

int 	main(void)
{
	t_input		*in;
	t_map		*map;

	in = NULL;
	map = NULL;
	init_structure(&map);
	read_input(&in, map);
	if (map->links[map->start][map->end] == '1')
		start_end_go(map);
	else if (map->ways->num && map->ants_num > 1)
		compose_ways(map);
//	else
//		ants_race(map);
	delete_structure(&map);
//	while (1)
//		;
	return (0);
}
