/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up_rx_moves_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:57:27 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 22:05:15 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cheker_bonus.h"

void	ra_move(t_list **stacka)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*stacka || !(*stacka)->next)
		return ;
	first = *stacka;
	second = first->next;
	last = find_last(*stacka);
	first->next = NULL;
	last->next = first;
	*stacka = second;
}

void	rb_move(t_list **stackb)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*stackb || !(*stackb)->next)
		return ;
	first = *stackb;
	second = first->next;
	last = find_last(*stackb);
	first->next = NULL;
	last->next = first;
	*stackb = second;
}

void	rr_bonus(t_list **stack_a, t_list **stack_b)
{
	ra_move(stack_a);
	rb_move(stack_b);
}
