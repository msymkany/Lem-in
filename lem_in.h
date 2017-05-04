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

typedef struct		s_map
{
	int		ants_num;
	char 	*start;
	char 	*end;
	t_r		*rooms;

}					t_map;

typedef	struct		s_r
{
	char 		*name;
	int			x;
	int			y;
	struct s_r	*next;
}					t_r;

t_input		*read_input(t_input **in);


/*
 ** managing structures
*/

void		init_structure(t_map **map);
t_input		*new_node(void);
void		push_to_list(t_input **head);



void		ft_error(void);

#endif