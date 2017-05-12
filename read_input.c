/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:11:02 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/28 17:11:06 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		read_input(t_input **in, t_map *map)
{
	validate_ant_num(in, map);
	validate_rooms(in, map);
	validate_links(in, map);
}
