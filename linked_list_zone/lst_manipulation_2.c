/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manipulation_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:05:34 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/16 18:09:35 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_top(t_list *head)
{
	int		max;
	t_list	*top;
	t_list	*current;

	top = head;
	current = head;
	max = current->nbr;
	while (current)
	{
		if (current->nbr > max)
		{
			top = current;
			max = current->nbr;
		}
		current = current->next;
	}
	return (top);
}

int	ft_lstsize(t_list *head)
{
	t_list	*current;
	int		i;

	current = head;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
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
