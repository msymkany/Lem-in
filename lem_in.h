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

int 				g_way;

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

typedef struct		s_way
{
	int 			*steps;
	int 			length;
	int 			num;
	int				second;
	int				penalt;
	struct s_way	*next;
}					t_way;

typedef struct		s_combo
{
	int				*way_combo;
	int				sum_ways;
	int 			sum_steps;
	float			index;
	int 			ant_num;
}					t_combo;

typedef struct		s_map
{
	int		ants_num;
	int		start;
	int 	end;
	int 	recursion;
	t_room	*rooms;
	char 	**links;
	t_way	*ways;
}					t_map;

typedef struct		s_race
{
	int 		sum_steps;
	int			*ants;
	int			index;
	char 		**rooms;
}					t_race;

/*
** validation
*/
void		validate_ant_num(t_input **in, t_map *map);
void		check_command_in_wrong_block(char *line);

void		validate_rooms(t_input **in, t_map *map);
void		check_room_format(t_map *map, char *line);
void		get_room_num(t_map *map);
void		check_command(char **line, t_map *map, t_input **in);
void		check_room_name_dub(t_map *map);
void		validate_room_coordinates(t_map *map);

void		validate_links(t_input **in, t_map *map);
void		init_adjacency_matrix(t_map *map);
/*
** main algorithm
*/
int			find_ways(t_map *map, int curr, int n, int max);
int			new_way(t_map *map, int n);
void		write_way(t_map *map);
void		start_end_go(t_map *map);
void		compose_ways(t_map *map);
t_combo		*find_shortest_way(int **tab, int l, int ants);
void		find_best_combo(int **tab, int **combo, t_map *map, t_combo *com);
void		ants_race(t_map *map, t_combo *com, int **tab);
void		sort_ways_in_combination(t_combo *com, int **tab);
t_race		**fill_in_race_struct(t_combo *com, int **tab, t_map *map);
/*
** managing structures
*/
void		init_structure(t_map **map);
void		delete_structure(t_map **map);
void		push_to_input(t_input **head, char *line);
void		push_to_room(t_room **head);
void		push_to_way(t_way **head);
int			**fill_in_tab(t_map *map);
int 		**init_combo_matrix(int	ways);
void		free_tabs(int **tab, int **combo, int l);
void		delete_race_struct(t_race **race, int sum_ways);
void		ft_error(char *str);

// test
void		print_input(t_input *head);
void		print_arr(char **map, int row);
void		print_rooms(t_room *head);
void		print_way(t_way *head);
void		print_int_arr(int **map, int row, int col);
void		print_combo(t_combo *com);
void		print_after_combo_sorting(int *combo, int **tab);

#endif