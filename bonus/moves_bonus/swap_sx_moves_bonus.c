/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sx_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:57:30 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 22:05:19 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cheker_bonus.h"

void	sa_move(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = *head;
	*head = second;
}

void	sb_move(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = *head;
	*head = second;
}

void	ss_move(t_list **heada, t_list **headb)
{
	sa_move(heada);
	sb_move(headb);
}
