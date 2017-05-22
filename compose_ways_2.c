/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compose_ways_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:31:09 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/22 19:31:13 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			**fill_in_tab(t_map *map)
{
	int 	i;
	int 	**tab;
	t_way	*ptr;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 3)))
		ft_error("malloc error, no allocation");
	while (i < 3)
	{
		if (!(tab[i++] = ft_int_strnew((size_t)map->ways->num + 1, 0)))
			ft_error("malloc error, no allocation");
	}
	ptr = map->ways;
	i = map->ways->num;
	while (ptr)
	{
		tab[0][i] = ptr->second;
		tab[1][i] = ptr->penalt;
		tab[2][i] = ptr->length - 1;
		ptr = ptr->next;
		i--;
	}
	return (tab);
}

int 		**init_combo_matrix(int	ways)
{
	int		**combo;
	size_t 	i;

	i = 0;
	if (!(combo = (int **)malloc(sizeof(int *) * ways)))
		ft_error("malloc error, no allocation");
	while (i < ways)
	{
		combo[i++] = NULL;
	}
	return (combo);
}

void		free_tabs(int **tab, int **combo, int l)
{
	size_t		i;

	i = 0;
	while (i < 3)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	if (combo)
	{
		i = 0;
		while (i <= l)
		{
			if (combo[i])
				free(combo[i]);
			i++;
		}
		free(combo);
		combo = NULL;
	}
}
