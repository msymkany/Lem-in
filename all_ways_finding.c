/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_ways_finding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:36:24 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/15 13:37:47 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		new_way(t_map *map, int n)
{
	push_to_way(&map->ways);
	map->ways->length = n;
	map->ways->steps = (int *)malloc(sizeof(int) * n);
	map->ways->steps[0] = map->start;
	map->ways->steps[n - 1] = map->end;
}

void		write_way(t_map *map)
{
	int 	curr;
	int 	i;
	int 	j;

	i = 1;
	curr = map->start;
	while (i < map->ways->length)
	{
		j = -1;
		while (map->links[curr][++j])
		{
			if (map->links[curr][j] == '#')
				break ;
		}
		map->ways->steps[i] = j;
		curr = j;
		i++;
	}

	print_way(map->ways); //test
//	print_arr(map->links, map->rooms->num + 1); // test
}
