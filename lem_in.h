/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:10:48 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/28 17:10:51 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Allowed functions:
 ** - malloc
 ** - free
 ** - read
 ** - write
 ** - strerror
 ** - perror
 ** - exit
 */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/includes/libft.h"
# include "libft/includes/libftprintf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct 		s_input
{
	char 			*line;
	struct s_input	*next;
}					t_input;

typedef	struct		s_room
{
	char 			*name;
	int				num;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_map
{
	int		ants_num;
	int		start;
	int 	end;
	t_room	*rooms;
	int 	**links;
}					t_map;

void		read_input(t_input **in, t_map *map);
void		validate_ant_num(t_input **in, t_map *map);
void		check_command_in_wrong_block(char *line);

void		validate_rooms(t_input **in, t_map *map);
void		check_room_format(t_map *map, char *line);
void		check_command(char **line, t_map *map, t_input **in);
void		check_room_name_dub(t_map *map);
void		validate_room_coordinates(t_map *map);

void		validate_links(t_input **in, t_map *map);
/*
** managing structures
*/

void		init_structure(t_map **map);
t_input		*new_node_input(void);
void		push_to_input(t_input **head, char *line);
t_room		*new_node_room(void);
void		push_to_room(t_room **head);


void		ft_error(char *str);

// test
void		print_input(t_input *head);

#endif