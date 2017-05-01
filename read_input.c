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

t_input		*read_input(void)
{
	t_input		*in;
	char 		*line;

	while (get_next_line(0, &line))
	{
		if (line[0] == '#')
			check_comment();
		ft_strdel(&line);
	}
	return (in);
}