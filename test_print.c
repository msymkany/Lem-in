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
		if (!map[i])
			ft_printf("%s", map[i]);
		else
		{
			j = 0;
			while (j < col)
			{
				ft_printf("%4d", map[i][j++]);
			}
		}
		ft_printf("\n");
		i++;
	}
}

void 	print_combo(t_combo *com)
{
	int 	i;

	i = 0;
	ft_printf("way combination\n");
	while (com->way_combo[i] != -1)
	{
		ft_printf("%d ", com->way_combo[i++]);
	}
	ft_printf("\nsum of ways: %d\n", com->sum_ways);
	ft_printf("sum of steps: %d\n", com->sum_steps);
	ft_printf("index: %d\n", com->index);
	ft_printf("ant num: %d\n", com->ant_num);
}