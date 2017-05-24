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

t_combo		*find_shortest_way(int **tab, int l, int ants)
{
	int 		i;
	t_combo		*com;

	i = 1;
	if (!(com = (t_combo *)malloc(sizeof(t_combo))))
		ft_error("malloc error, no allocation");
	com->way_combo = ft_int_strnew(l + 1, -1);
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
//	ft_printf("shortest way %d\n", com->way_combo[0]); // test
	return (com);
}

int 		check_intersection(int **combo, int *set, int s, int way_2)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < s)
	{
		j = 0;
		while (combo[way_2][j])
		{
			if (combo[way_2][j] == set[i])
				break ;
		}
		if (!combo[i][j])
			return (0);
		i++;
	}
	return (1);
}

int			find_index(t_combo *set, int steps, int way, int s)
{
	int 	new_step_sum;
	int 	new_index;

	new_step_sum = set->sum_steps + steps;
	new_index = (new_step_sum + set->ant_num) / (set->sum_ways + 1);
	if (new_index < set->index)
	{
		set->way_combo[s] = way;
		set->index = new_index;
		set->sum_ways += 1;
		set->sum_steps = new_step_sum;
		return (++s);
	}
	return (s);
}

int			find_combo(int **tab, int **combo, int i, t_combo *set)
{
	int 	j;
	int 	s;
	int 	current;

	j = 1;
	s = 2;
	set->way_combo[0] = i;
	set->way_combo[1] = combo[i][0];
	set->sum_ways = 2;
	set->sum_steps = tab[2][i] + tab[2][combo[i][0]];
	set->index = (set->sum_steps + set->ant_num) / 2;
	while (combo[i][j])
	{
		current = combo[i][j];
		if (check_intersection(combo, set->way_combo, s, combo[i][j]))
		{
			s = find_index(set, tab[2][current], current, s);
		}
		j++;
	}
	return (set->index);
}

void		find_best_combo(int **tab, int **combo, t_map *map, t_combo *com)
{
	int 		i;
	t_combo		*set;

	i = 0;
	if (!(set = (t_combo *)malloc(sizeof(t_combo))))
		ft_error("malloc error, no allocation");
	set->way_combo = ft_int_strnew(map->ways->num + 1, -1);
	set->ant_num = map->ants_num;
	while (i <= map->ways->num)
	{
		if (combo[i])
		{
			find_combo(tab, combo, i, set);
			compare_combo(set, com);
		}
		i++;
	}
	free(set->way_combo);
	free(set);
}
