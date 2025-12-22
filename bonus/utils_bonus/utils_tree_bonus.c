/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tree_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:12:04 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 23:56:07 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cheker_bonus.h"

void	free_memory(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	cheek_integer_forme(char *str)
{
	int	nbr ;

	nbr = ft_atoi(str);
	return (0);
}

int	sps(char c)
{
	return (9 <= c && c <= 13 || c == 32);
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
