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

void		push_to_input(t_input **head, char *line)
{
	t_input		*new;

	new = (t_input *)malloc(sizeof(t_input));
	if (!new)
		ft_error("malloc error, no allocation");
	else
	{
		new->next = NULL;
		new->line = NULL;
	}
	new->line = ft_strdup(line);
	new->next = *head;
	*head = new;
}

void		push_to_room(t_room **head)
{
	t_room		*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (!new)
		ft_error("malloc error, no allocation");
	else
	{
		new->next = NULL;
		new->name = NULL;
		new->x = 0;
		new->y = 0;
	}
	new->next = *head;
	*head = new;
}

void		push_to_way(t_way **head)
{
	t_way		*new;

	new = (t_way *)malloc(sizeof(t_way));
	if (!new)
		ft_error("malloc error, no allocation");
	else
	{
		new->next = NULL;
		new->steps = NULL;
		new->length = 0;
	}
	new->next = *head;
	*head = new;
}
