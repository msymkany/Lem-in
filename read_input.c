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

t_input		*read_input(t_input **in)
{
	t_input		*in;
	char 		*line;

	while (get_next_line(0, &(*in)->line))
	{
		if ((*in)->line[0] == '#')
		{
			check_comment();
			push_to_list(in);
		}
		else if (!(**in)->line)
			ft_error();
		else
		{
			get_n_ants((*in)->line);

		}
	}
	return (in);
}