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

int 		push_ants(t_race **race, int sum_ways, int id_ant)
{
	int		i;

	i = 0;
	if (id_ant == 1)
	{
		ft_printf("\033[;36mL1-%s\033[;0m", race[i]->rooms[i]);
		race[i++]->ants[0] = id_ant++;
	}
	while (i < sum_ways)
	{
		ft_printf("\033[;36m L%d-%s\033[;0m", id_ant, race[i]->rooms[0]);
		race[i++]->ants[0] = id_ant++;
	}
	return (id_ant);
}

int 		move_last(t_race **race)
{
	int 	move;
	int 	i;
	int 	j;

	i = 0;
	move = 0;
	while (race[i])
	{
		j = race[i]->sum_steps - 2;
		if (race[i]->ants[j])
		{
			if (move)
				ft_printf(" ");
			ft_printf("\033[;35mL%d-%s\033[;0m", race[i]->ants[j],
					  race[i]->rooms[j + 1]);
			race[i]->ants[j] = 0;
			move++;
		}
		i++;
	}
	return (move);
}

int			move_ants(t_race **race)
{
	int 	i;
	int 	j;
	int 	move;

	i = 0;
	move = move_last(race);
	while (race[i])
	{
		j = race[i]->sum_steps - 1;
		while (--j >= 0)
		{
			if (race[i]->ants[j])
			{
				if (move)
					ft_printf(" ");
				ft_printf("\033[;34mL%d-%s\033[;0m", race[i]->ants[j],
						  race[i]->rooms[j + 1]);
				race[i]->ants[j + 1] = race[i]->ants[j];
				race[i]->ants[j] = 0;
				move++;
			}
		}
		i++;
	}
	return (move);
}

void		ants_start(t_race **race, int sum_ways, int sum_ants, int id_ant)
{
	int 		stop_ants;

	if (sum_ants <= 0)
	{
		while (move_ants(race))
			ft_printf("\n");
		return ;
	}
	else
	{
		stop_ants = ((sum_ants - race[sum_ways - 1]->index) / sum_ways);
//		ft_printf("stop_ants: %d\n", stop_ants);		//test
		while (stop_ants-- > 0)
		{
			if (id_ant > 1)
				move_ants(race);
			id_ant = push_ants(race, sum_ways, id_ant);
			ft_printf("\n");
			if (stop_ants == 0)
				sum_ants = sum_ants - id_ant + 1;
		}
		ants_start(race, --sum_ways, sum_ants, id_ant);
	}
}

void		ants_race(t_map *map, t_combo *com, int **tab)
{
	t_race		**race;

	if (com->sum_ways > 1)
		sort_ways_in_combination(com, tab);
	print_after_combo_sorting(com->way_combo, tab); // test
	race = fill_in_race_struct(com, tab, map);
	ants_start(race, com->sum_ways, map->ants_num, 1);
	delete_race_struct(race, com->sum_ways);
}
