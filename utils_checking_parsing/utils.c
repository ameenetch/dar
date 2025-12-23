/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:50:43 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/17 17:07:11 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	cheek_already_sorted(t_list **head)
{
	t_list	*current;
	t_list	*nextnode;
	int		flag;

	flag = 0;
	current = *head;
	nextnode = current->next;
	while (current)
	{
		nextnode = current->next;
		if (nextnode && current->nbr > nextnode->nbr)
		{
			flag = 1;
			break ;
		}
		current = nextnode;
	}
	if (flag)
		return ;
	lst_clear(head);
	exit(0);
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
