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
	(*map)->rooms = NULL;
	(*map)->links = NULL;
}
