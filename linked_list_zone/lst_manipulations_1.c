/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manipulations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:05:43 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/16 18:09:10 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_node(int data)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->nbr = data;
	newnode->next = NULL;
	return (newnode);
}

void	add_head(t_list **head, int data)
{
	t_list	*newnode;

	if (!*head)
	{
		*head = create_node(data);
		return ;
	}
	newnode = create_node(data);
	newnode->next = *head;
	*head = newnode;
}

void	add_back(t_list **head, int data)
{
	t_list	*newnode;
	t_list	*lastnode;

	newnode = create_node(data);
	if (!*head)
	{
		*head = newnode;
		return ;
	}
	lastnode = find_last(*head);
	lastnode->next = newnode;
}

t_list	*find_last(t_list *head)
{
	t_list	*current;

	current = head;
	while (current->next)
		current = current->next;
	return (current);
}

t_list	*find_pre_last(t_list *head)
{
	t_list	*current;

	current = head;
	while (current->next->next)
		current = current->next;
	return (current);
}
