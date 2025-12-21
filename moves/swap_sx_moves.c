/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sx_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:57:30 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/21 21:38:56 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	write(0, "sa\n", 3);
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
	write(0, "sb\n", 3);
}

void	ss_move(t_list **heada, t_list **headb)
{
	sa_move(heada);
	sb_move(headb);
	write(0, "ss\n", 3);
}
