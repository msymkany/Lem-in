/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:10:34 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/28 17:10:42 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	main(void)
{
	t_input		*in;
	t_map		*map;

	in = NULL;
	map = NULL;
	init_structure(&map);
//	in = new_node();
	read_input(&in, map);

	return (0);
}