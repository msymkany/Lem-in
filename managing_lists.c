/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:15:27 by msymkany          #+#    #+#             */
/*   Updated: 2017/05/06 13:15:44 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_input		*new_node_input(void)
{
	t_input		*new;

	new = (t_input *)malloc(sizeof(t_input));
	if (new)
	{
		new->next = NULL;
		new->line = NULL;
	}
	return (new);
}

void		push_to_input(t_input **head, char *line)
{
	t_input		*new;

	new = new_node_input();
	new->line = ft_strdup(line);
	new->next = *head;
	*head = new;
}

t_room		*new_node_room(void)
{
	t_room		*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (!new)
		ft_error();
	else
	{
		new->next = NULL;
		new->name = NULL;
		new->x = 0;
		new->y = 0;
	}
	return (new);
}

void		push_to_room(t_room **head)
{
	t_room		*new;

	new = new_node_room();
	new->next = *head;
	*head = new;
}
