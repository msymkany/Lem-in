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

}					t_map;

t_input		*read_input(t_input **in, t_map *map);
void		check_comment_ant_num_block(char *line);

/*
** managing structures
*/

void		init_structure(t_map **map);
t_input		*new_node_input(void);
void		push_to_input(t_input **head, char *line);
t_room		*new_node_room(void);
void		push_to_room(t_room **head);


void		ft_error(void);

// test
void		print_input(t_input *head);

#endif