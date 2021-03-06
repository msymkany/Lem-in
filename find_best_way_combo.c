/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_way_combo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 20:58:25 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/22 20:58:29 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			find_index(t_combo *set, int steps, int way, int s)
{
	long long 	new_step_and_ants;
	float 	new_index;

	new_step_and_ants = set->sum_steps + steps + (long long)set->ant_num;
	if (new_step_and_ants >= 2147483647)
		new_step_and_ants = new_step_and_ants / 2;
	new_index = (float)new_step_and_ants / ((float)set->sum_ways + 1);
	if (new_index < set->index)
	{
		set->way_combo[s] = way;
		set->index = new_index;
		set->sum_ways += 1;
		set->sum_steps = set->sum_steps + steps;
		return (++s);
	}
	return (s);
}

int 		check_intersection(int **combo, int *set, int s, int way_2)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < s)
	{
		j = 0;
		while (combo[way_2][j] != -1)
		{
			if (combo[way_2][j] == set[i])
				break ;
			j++;
		}
		if (combo[way_2][j] == -1)
			return (0);
		i++;
	}
	return (1);
}

t_combo		*find_combo(int **tab, int **combo, int i, t_combo *set)
{
	int 	j;
	int 	s;
	int 	current;
	long long new_step_and_ants;

	j = 1;
	s = 2;
	set->way_combo[0] = i;
	set->way_combo[1] = combo[i][0];
	set->sum_ways = 2;
	set->sum_steps = tab[2][i] + tab[2][combo[i][0]];
	if ((new_step_and_ants = set->sum_steps + (long long)set->ant_num) >= 2147483647)
		new_step_and_ants = new_step_and_ants / 2;
//	set->index = ((float)set->sum_steps + (float)set->ant_num) / 2;
	set->index = (float)new_step_and_ants / 2;
	while (combo[i][j] != -1)
	{
		if (set->sum_ways == set->ant_num)		//test
			break;
		current = combo[i][j];
		if (check_intersection(combo, set->way_combo, s, combo[i][j]))
		{
			s = find_index(set, tab[2][current], current, s);
		}
		j++;
	}
	return (set);
}

void		compare_combo(t_combo *set, t_combo *com)
{
	int 	i;

	i = 0;
	if (set->index < com->index)
	{
		while (set->way_combo[i] != -1)
		{
			com->way_combo[i] = set->way_combo[i];
			i++;
		}
		com->sum_ways = set->sum_ways;
		com->sum_steps = set->sum_steps;
		com->index = set->index;
		i = 0;
	}
	while (set->way_combo[i] != -1)
		set->way_combo[i++] = -1;
}

void		find_best_combo(int **tab, int **combo, t_map *map, t_combo *com)
{
	int 		i;
	t_combo		*set;

	i = 0;
	if (!(set = (t_combo *)malloc(sizeof(t_combo))))
		ft_error("malloc error, no allocation");
	set->way_combo = ft_int_strnew(map->ways->num + 2, -1);
	set->ant_num = map->ants_num;
	while (i <= map->ways->num)  //&& com->sum_ways != map->ants_num)
	{
		if (combo[i])
		{
			set = find_combo(tab, combo, i, set);
			compare_combo(set, com);
		}
		i++;
	}
	free(set->way_combo);
	free(set);
}
