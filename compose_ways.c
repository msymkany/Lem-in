/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:52:31 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/20 17:52:36 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 		check_rooms_intersection(t_map *map, int *rooms, int way)
{
	t_way	*ptr;
	size_t 	i;

	ptr = map->ways;
	while (ptr)
	{
		if (way == ptr->num)
		{
			i = 1;
			while (ptr->steps[i] != map->end)
			{
				if (rooms[ptr->steps[i]] == 1)
					return (0);
				else
					rooms[ptr->steps[i]] = 1;
				i++;
			}
		}
		ptr = ptr->next;
	}
	return (1);
}

int 		check_way_intersection(t_map *map, int x, int y)
{
	int 	*rooms;
	int 	i;

	i = 0;
	if (!(rooms = ft_int_strnew((size_t)map->rooms->num + 1, 0)))
		ft_error("malloc error, no allocation");
	check_rooms_intersection(map, rooms, x);
	if (check_rooms_intersection(map, rooms, y))
		i = 1;
	free(rooms);
	rooms = NULL;
	return (i);
}

void		find_way_combination(t_map *map, int id, int **tab, int **combo)
{
	int 	i;
	int 	j;
	int 	l;

//	i = id + 1;
	i = 0;
	j = 0;
	l = 0;
	while (i <= map->ways->num)
	{
		if (tab[0][id] != tab[0][i] && tab[1][id] != tab[1][i])
		{
			if (check_way_intersection(map, id, i))
			{
				if (!combo[id])
					combo[id] = ft_int_strnew((size_t)map->ways->num + 1, -1);
				if (!combo[i])
					combo[i] = ft_int_strnew((size_t)map->ways->num + 1, -1);
				combo[id][j++] = i;
				if (i > id)
				{
					while (combo[i][l] != -1)
						l++;
					combo[i][l] = id;
				}
			}
		}
		i++;
	}
}

t_combo		*find_shortest_way(int **tab, int l, int ants)
{
	int 		i;
	t_combo		*com;

	i = 1;
	if (!(com = (t_combo *)malloc(sizeof(t_combo))))
		ft_error("malloc error, no allocation");
	com->way_combo = ft_int_strnew(l + 2, -1);
	com->way_combo[0] = 0;
	com->sum_ways = 1;
	com->sum_steps = tab[2][0];
	com->ant_num = ants;
	while (i <= l)
	{
		if (tab[2][i] < com->sum_steps)
		{
			com->sum_steps = tab[2][i];
			com->way_combo[0] = i;
		}
		i++;
	}
	com->index = ants + com->sum_steps;
	return (com);
}

void		compose_ways(t_map *map)
{
	int			**combo;
	int			i;
	int			**tab;
	t_combo		*com;

	i = 0;
	tab = fill_in_tab(map);
	print_int_arr(tab, 3, map->ways->num + 1);   // test
	com = find_shortest_way(tab, map->ways->num, map->ants_num);
	ft_printf("shortest way %d\n", com->way_combo[0]); // test
	if (map->ants_num == 1)
		ants_race(map, com, tab);
	else
	{
		combo = init_combo_matrix(map->ways->num + 1);
		ft_printf("\n -------------------------------------- \n"); // test
		while (i < map->ways->num)
		{
			find_way_combination(map, i, tab, combo);
			i++;
		}
		print_int_arr(combo, map->ways->num + 1, map->ways->num + 1);   // test
		find_best_combo(tab, combo, map, com);
		print_combo(com);
		ants_race(map, com, tab);
	}
	free_tabs(tab, combo, map->ways->num);
}
