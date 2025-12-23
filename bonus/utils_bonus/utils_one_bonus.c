/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:04:46 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 23:55:34 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cheker_bonus.h"

void	indexing(t_list **head)
{
	t_list	*current;
	t_list	*prev;
	int		index;

	current = *head;
	while (current)
	{
		index = 0;
		prev = *head;
		while (prev)
		{
			if (current->nbr > prev->nbr)
				index++;
			prev = prev->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (b[i] && a[i] && a[i] == b[i])
		i++;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

void	cheek_string_arg(char *str)
{
	int		i;
	char	**splits;

	i = 0;
	splits = ft_split(str);
	if (!splits)
		ft_error();
	while (splits[i])
	{
		if (!checker(splits[i]))
		{
			free_memory(splits);
			ft_error();
		}
		i++;
	}
	free_memory(splits);
}

void	cheek_double(t_list **head)
{
	t_list	*current;
	t_list	*nextnode;

	current = *head;
	indexing(head);
	while (current)
	{
		nextnode = current->next;
		while (nextnode)
		{
			if (nextnode->index == current->index)
			{
				lst_clear(head);
				ft_error();
			}
			nextnode = nextnode->next;
		}
		current = current->next;
	}
}
