/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_race.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:15:32 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/18 16:15:35 by msymkany         ###   ########.fr       */
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

void		ants_race(t_map *map, t_combo *com, int **tab)
{
	t_race		**race;
// tab[2][0] = 6; //test
//	tab[2][3] = 3; //test
	if (com->sum_ways > 1)
		sort_ways_in_combination(com, tab);
	print_after_combo_sorting(com->way_combo, tab); // test
	race = fill_in_race_struct(com, tab, map);

	delete_race_struct(race, com->sum_ways);
}
