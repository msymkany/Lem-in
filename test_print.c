/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 15:32:51 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/06 15:32:53 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_input(t_input *head)
{
	while (head)
	{
		ft_printf("%s\n", head->line);
		head = head->next;
	}
}

void	print_arr(char **map, int row)
{
	int 	i;

	i = 0;
	while (i < row)
	{
		ft_printf("%s\n", map[i++]);
	}
}

void		print_rooms(t_room *head)
{
	while (head)
	{
		ft_printf("name: %s, num: %d\n", head->name, head->num);
		head = head->next;
	}
}

void		print_way(t_way *head)
{
	int 	i;

	i = 0;
	while (head)
	{
		ft_printf("step: ");
		while (i < head->length)
		{
			ft_printf("%d ", head->steps[i]);
			i++;
		}
		ft_printf("\nlength %d\n", head->length);
		head = head->next;
	}
}
