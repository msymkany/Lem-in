/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 17:45:00 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/06 17:45:10 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		validate_links(t_input **in, t_map *map)
{
	char 	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!line)
			ft_error();
		else if (line[0] == '#')
		{
			push_to_input(in, line);
		}
		else
		{
			push_to_input(in, line);
		}
		ft_strdel(&line);
	}
	write(1, "OK ants num\n", 3); // test
	ft_printf("%d\n", map->ants_num); // test
	print_input(*in);  // test
}
