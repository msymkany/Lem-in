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
	map->ways->second = 0;
	map->ways->penalt = 0;
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
	map->ways->second = map->ways->steps[1];
	map->ways->penalt = map->ways->steps[l - 1];
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

//void		new_way_combination(t_map *map, t_way **combo)
//{
//	size_t		j;
//
//	j = 0;
//	push_to_way(combo);
//	(*combo)->length = (map->ways->num + 1);
//	(*combo)->steps = (int *)malloc(sizeof(int) * ((*combo)->length));
//	while (j < (*combo)->length)
//	{
//		(*combo)->steps[j] = j;
//		j++;
//	}
//	if ((*combo)->next)
//	(*combo)->num = (*combo)->next->num + 1;
//}
//
//int 		*get_way(t_map *map, int id)
//{
//	t_way	*ptr;
//
//	ptr = map->ways;
//	while (ptr)
//	{
//		if (ptr->num == id)
//			break ;
//		ptr = ptr->next;
//	}
//	return (ptr->steps);
//}
//
int 		check_way_intersection(t_map *map, int *combo)
{
	int 	*rooms;
	int 	i;
	t_way	*ptr;

	if (!(rooms = (int *)malloc(sizeof(int ) * (map->rooms->num + 1))))
		ft_error("malloc error, no allocation");
	while ()
//		ptr = map->ways;
//	while (ptr)
//	{
//		if (i < ptr->num)
//		{
//
//		}
//		i++;
//		ptr = ptr->next;
//	}
	free(rooms);
	rooms = NULL;
}

void		find_way_combination(t_map *map, int id, int **tab, t_combo **combo)
{
	int 	i;
	int 	*way;
	int 	sum_ways;
	int 	sum_steps;

	i = id + 1;
	tab[3][id] = 1;
	while (i <= map->ways->num)
	{
		if (tab[0][id] != tab[0][i] && tab[1][id] != tab[1][i])
		{
			tab[3][id] = 1;
		}
		i++;
	}
}

int			**fill_in_tab(t_map *map)
{
	int 	i;
	int 	**tab;
	t_way	*ptr;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 4)))
		ft_error("malloc error, no allocation");
	while (i <= map->ways->num)
	{
		if (!(tab[i++] = (int *)malloc(sizeof(int ) * (map->ways->num + 1))))
			ft_error("malloc error, no allocation");
	}
	ptr = map->ways;
	while (ptr)
	{
		i--;
		tab[0][i] = ptr->second;
		tab[1][i] = ptr->penalt;
		tab[2][i] = ptr->length - 1;
		tab[3][i] = 0;
		ptr = ptr->next;
	}
	return (tab);
}

void		compose_ways(t_map *map)
{
	t_combo	*combo;
	int 	i;
	int 	**tab;

	i = 0;
	tab = fill_in_tab(map);
	print_int_arr(tab, 4, map->ways->num + 1);
	while (i < map->ways->num)
	{
		find_way_combination(map, i, tab, &combo);
		i++;
	}

}
