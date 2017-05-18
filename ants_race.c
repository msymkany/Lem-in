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

void		ants_race(t_map *map)
{

}
