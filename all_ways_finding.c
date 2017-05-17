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
	if (map->ways->next)
		map->ways->num = map->ways->next->num + 1;
}

void		write_way(t_map *map)
{
	int 	curr;
	int 	i;
	int 	j;
	int 	l;

	i = 1;
	curr = map->start;
	l = map->ways->length - 1;
	while (i < l)
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
}

int			find_ways(t_map *map, int curr, int previous, int n)
{
	int		i;

	i = 0;
	if (curr == map->end)
	{
		new_way(map, n);
		return (1);
	}
	while (map->links[curr][i])
	{
		if (map->links[curr][i] == '1' && i != previous)
		{
			map->links[curr][i] = '#';
			if (!find_ways(map, i, curr, n + 1))
				map->links[curr][i] = '1';
			else
			{
				write_way(map);
				map->links[curr][i] = '1';
			}
		}
		i++;
	}
	return (0);
}

void		compose_ways(t_map *map)
{

}