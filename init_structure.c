/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:05:07 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/04 16:05:09 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_structure(t_map **map)
{
	*map = (t_map *)malloc(sizeof(t_map));
	if (!(*map))
		ft_error("malloc error, no allocation");
	(*map)->ants_num = 0;
	(*map)->start = -1;
	(*map)->end = -1;
	(*map)->recursion = 0; ///test
	(*map)->rooms = NULL;
	(*map)->links = NULL;
	(*map)->ways = NULL;
}

void		init_adjacency_matrix(t_map *map)
{
	int 	i;
	int 	j;

	i = map->rooms->num + 1;
	j = 0;
	map->links = (char **)malloc(sizeof(char*) * (i + 1));
	if (!map->links)
		ft_error("malloc error, no allocation");
	map->links[i] = NULL;
	while (j < i)
	{
		map->links[j] = ft_strnew(i);
		ft_memset(map->links[j], '0', i);
		j++;
	}
}

void 	delete_structure(t_map **map)
{
	t_room		*ptr;

	if ((*map)->rooms)
	{
		ptr = (*map)->rooms;
		while ((ptr = ptr->next))
		{
			if (ptr->name)
				ft_strdel(&ptr->name);
		}
	}
}