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

int		new_way(t_map *map, int n)
{
	push_to_way(&map->ways);
	map->ways->length = n;
	map->ways->steps = (int *)malloc(sizeof(int) * n);
	map->ways->steps[0] = map->start;
	map->ways->steps[n - 1] = map->end;
	map->ways->second = 0;
	map->ways->penalt = 0;
	if (map->ways->next)
		map->ways->num = map->ways->next->num + 1;
	map->recursion++;
	return (1);
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
		while (map->links[curr] && map->links[curr][++j])
		{
			if (map->links[curr][j] == '#')
			{
				map->ways->steps[i] = j;
				curr = j;
				break ;
			}
		}
		i++;
	}
	map->ways->second = map->ways->steps[1];
	map->ways->penalt = map->ways->steps[l - 1];
//	g_way++;
//	if (g_way / 10 == 0)							//test
//		ft_printf("Found %d ways\n", g_way);
//	print_arr(map->links, map->rooms->num + 1);   //test
//	ft_printf("\n -------------------------------------- \n"); //test
}

void		check_end_room(t_map *map, int curr, int *max, int *i)
{
	if (map->links[curr][map->end] == '1' && !(*max))
	{
		(*i) = map->end;
		(*max) = 1;
	}
}

int			find_ways(t_map *map, int curr, int n, int max)
{
	int		i;

	i = -1;
	if (n > 3 && map->recursion >= 3)
		return (0);
	if (curr == map->end)
		return (new_way(map, n));
	while (map->links[curr][++i])
	{
		check_end_room(map, curr, &max, &i);
		if (n == 3)
			map->recursion = 0;
		if (map->links[curr][i] == '1' && !(ft_strchr(map->links[i], '#')))
		{
			map->links[curr][i] = '#';
			if (!find_ways(map, i, n + 1, max))
					;
			else
				write_way(map);
			map->links[curr][i] = '1';
		}
	}
	return (0);
}
