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

static int		check_link_name(char *str, t_map *map)
{
	t_room		*ptr;

	ptr = map->rooms;
	while (ptr)
	{
		if (ft_strequ(ptr->name, str))
			return (ptr->num);
		ptr = ptr->next;
	}
	ft_error("no match between link and room names");
	return (0);
}

static void		get_links(t_map *map, char *line)
{
	char		**link;
	size_t		i;
	int		link_1;
	int		link_2;

	i = 0;
	link = ft_strsplit(line, '-');
	while (link[i])
		i++;
	if (i != 2)
		ft_error("wrong link format");
	link_1 = check_link_name(link[0], map);
	link_2 = check_link_name(link[1], map);
	if (link_1 != link_2)
	{
		map->links[link_1][link_2] = '1';
		map->links[link_2][link_1] = '1';
	}
	i = 0;
	while (link[i])
	{
		ft_strdel(&link[i++]);
	}
	free(link);
	link = NULL;
}

static void		check_start_end_links(char *start, char *end)
{
	size_t		i;

	i = 0;
	while (start[i])
	{
		if (start[i] == '1')
			break ;
		i++;
	}
	if (start[i] != '1')
		ft_error("no link to start room");
	i = 0;
	while (end[i])
	{
		if (end[i] == '1')
			break ;
		i++;
	}
	if (end[i] != '1')
		ft_error("no link to end room");
}

static int			check_way_existance(t_map *map)
{
	int		max_ways;

	max_ways = (map->rooms->num + 1) * (map->rooms->num + 1);
	if (map->links[map->start][map->end] == '1')
		return (1);
	else
	{
		find_ways(map, map->start, 1, 0);
		if (map->ways)
			return (1);
	}
	return (0);
}


void			validate_links(t_input **in, t_map *map)
{
	char 	*line;

	line = NULL;
	init_adjacency_matrix(map);
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
	ft_strdel(&line);
	check_start_end_links(map->links[map->start], map->links[map->end]);
	if (!check_way_existance(map))
		ft_error("no way from start to end");
//	print_way(map->ways); //test
//	write(1, "OK links\n", 9); // test
//	print_arr(map->links, map->rooms->num + 1);
//	print_input(*in);  // test
}
