/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up_rx_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:57:27 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 21:04:56 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rr_move(t_list **stacka, t_list **stackb)
{
	ra_move(stacka);
	rb_move(stackb);
	write(1, "rr\n", 3);
}
