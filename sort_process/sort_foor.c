/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_foor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:45:45 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/16 16:45:45 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	adapte_stack(int pos, t_list **head)
{
	if (pos == 1)
		sa_move(head);
	else if (pos == 2)
	{
		rra_move(head);
		rra_move(head);
	}
	else if (pos == 3)
		rra_move(head);
}

void	sorting_foor(t_list **stackA, t_list **stackB)
{
	t_list	*current ;
	int		pos ;

	indexing(stackA);
	pos = 0;
	current = *stackA ;
	while (current)
	{
		if (current->index == 0)
			break ;
		pos++;
		current = current->next;
	}
	adapte_stack(pos, stackA);
	pb_move(stackB, stackA);
	sorting_three(stackA);
	pa_move(stackA, stackB);
}
