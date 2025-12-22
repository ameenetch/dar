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

void	sorting_foor(t_list **stacka, t_list **stackb)
{
	t_list	*current ;
	int		pos ;

	indexing(stacka);
	pos = 0;
	current = *stacka ;
	while (current)
	{
		if (current->index == 0)
			break ;
		pos++;
		current = current->next;
	}
	adapte_stack(pos, stacka);
	pb_move(stacka, stackb);
	sorting_three(stacka);
	pa_move(stacka, stackb);
}
