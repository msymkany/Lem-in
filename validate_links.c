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

void		get_links(t_map *map, char *line)
{
	char		**link;
	size_t		i;
	int		*link_1;
	int		*link_2;

	link_1 = 0;
	link_2 = 0;
	i = 0;
	link = ft_strsplit(line, '-');
	while (link[i])
		i++;
	if (i != 2)
		ft_error("wrong link format");
	

}

void		validate_links(t_input **in, t_map *map)
{
	char 	*line;
//	int 	iterations;

//	iterations = 1;
	line = NULL;
	get_links(map, (*in)->line);
	while (get_next_line(0, &line))
	{
		if (!line)
			ft_error("empty line");
		else if (line[0] == '#')
		{
			check_command_in_wrong_block(line);
			push_to_input(in, line);
		}
		else
		{
			get_links(map, line);
			push_to_input(in, line);
		}
		ft_strdel(&line);
	}
	write(1, "OK ants num\n", 3); // test
	ft_printf("%d\n", map->ants_num); // test
	print_input(*in);  // test
}
