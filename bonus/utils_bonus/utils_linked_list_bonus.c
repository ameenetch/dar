/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_list_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:30:39 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 23:56:14 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cheker_bonus.h"

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

void	lst_clear(t_list **head)
{
	t_list	*current;
	t_list	*nextnode;

	current = *head;
	while (current)
	{
		nextnode = current->next;
		free(current);
		current = nextnode;
	}
	*head = NULL;
}

t_list	*find_pre_last(t_list *head)
{
	t_list	*current;

	current = head;
	while (current->next->next)
		current = current->next;
	return (current);
}
