/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_race_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:20:04 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/29 14:20:07 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		start_end_go(t_map *map)
{
	size_t		i;
	t_room		*ptr;

	ptr = map->rooms;
	while (ptr)
	{
		if (ptr->num == map->end)
			break ;
	}
	i = 1;
	while (i <= map->ants_num)
	{
		ft_printf("L%d-%s", i, ptr->name);
		(i == map->ants_num) ? (ft_printf("\n")) : (ft_printf(" "));
		i++;
	}
}

void		sort_ways_in_combination(t_combo *com, int **tab)
{
	int		i;
	int 	j;
	int 	way_1;
	int 	way_2;

	i = 1;
	j = -1;
	while (i < com->sum_ways)
	{
		way_1 = com->way_combo[i - 1];
		way_2 = com->way_combo[i];
		if (tab[2][way_2] < tab[2][way_1])
		{
			j = com->way_combo[i];
			com->way_combo[i] = com->way_combo[i - 1];
			com->way_combo[i - 1] = j;
		}
		i++;
	}
	if (j > -1)
		sort_ways_in_combination(com, tab);
	else
		return ;
}

char		**fill_in_room_names(t_map *map, int way, int steps)
{
	size_t		i;
	t_way		*ptr_way;
	t_room		*ptr_room;
	char		**rooms;

	i = 1;
	ptr_way = map->ways;
	if (!(rooms = (char **)malloc(sizeof(char *) * (steps + 1))))
		ft_error("malloc error, no allocation");
	rooms[steps] = NULL;
	while (ptr_way->num != way)
	{
		ptr_way = ptr_way->next;
	}
	while (i <= steps)
	{
		ptr_room = map->rooms;
		while (ptr_room->num != ptr_way->steps[i])
			ptr_room = ptr_room->next;
		rooms[i - 1] = ft_strdup(ptr_room->name);
		i++;
	}
	return (rooms);
}

void		delete_race_struct(t_race **race, int sum_ways)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < sum_ways)
	{
		j = 0;
		free(race[i]->ants);
		while (race[i]->rooms[j])
			free(race[i]->rooms[j++]);
		free(race[i]->rooms);
		free(race[i]);
		i++;
	}
	free(race);
}

t_race		**fill_in_race_struct(t_combo *com, int **tab, t_map *map)
{
	t_race		**race;
	size_t		i;
	int			len_0;

	i = 0;
	len_0 = tab[2][com->way_combo[i]];
	if (!(race = (t_race **)malloc(sizeof(t_race *) * (com->sum_ways + 1))))
		ft_error("malloc error, no allocation");
	race[com->sum_ways] = NULL;
	while (i < com->sum_ways)
	{
		if (!(race[i] = (t_race *)malloc(sizeof(t_race))))
			ft_error("malloc error, no allocation");
		race[i]->sum_steps = tab[2][com->way_combo[i]];
		race[i]->ants = ft_int_strnew(race[i]->sum_steps, 0);
		race[i]->index = race[i]->sum_steps - len_0 + i;
		race[i]->rooms = fill_in_room_names(map, com->way_combo[i],
						race[i]->sum_steps);
		ft_printf("number of way: %d\n", com->way_combo[i]); // test
		ft_printf("steps: %d\n", race[i]->sum_steps);		// test
		ft_printf("index: %d\n", race[i]->index);		// test
		print_arr(race[i]->rooms, race[i]->sum_steps);	// test
		i++;
	}
	return (race);
}
