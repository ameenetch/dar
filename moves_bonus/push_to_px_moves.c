/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_px_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:57:23 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/21 21:53:20 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;

	if (!*stack_b)
		return ;
	tmp_b = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(tmp_b)->next = NULL;
	(tmp_b)->next = (*stack_a);
	(*stack_a) = tmp_b;
}

void	pb_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_at_a;

	if (!*stack_a)
		return ;
	first_at_a = *stack_a;
	(*stack_a) = (*stack_a)->next ;
	first_at_a->next = NULL;
	first_at_a->next = (*stack_b);
	(*stack_b) = first_at_a ;
}
