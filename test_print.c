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

	while (head)
	{
		ft_printf("%d way\n", head->num);
		ft_printf("step: ");
		i = 0;
		while (i < head->length)
		{
			ft_printf("%d ", head->steps[i]);
			i++;
		}
		ft_printf("\nlength %d\n", head->length);
		head = head->next;
	}
}

void	print_int_arr(int **map, int row, int col)
{
	size_t 	i;
	size_t 	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			ft_printf("%4d", map[i][j++]);
		}
		ft_printf("\n");
		i++;
	}
}
