/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down_rrx_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:57:19 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/21 21:38:34 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_move(t_list **stacka)
{
	t_list	*first;
	t_list	*last;
	t_list	*prelast;

	if (!*stacka || !(*stacka)->next)
		return ;
	first = *stacka;
	last = find_last(*stacka);
	prelast = find_pre_last(*stacka);
	prelast->next = NULL;
	last->next = first;
	*stacka = last;
	write(0, "rra\n", 4);
}

void	rrb_move(t_list **stackb)
{
	t_list	*first;
	t_list	*last;
	t_list	*prelast;

	if (!*stackb || !(*stackb)->next)
		return ;
	first = *stackb;
	last = find_last(*stackb);
	prelast = find_pre_last(*stackb);
	prelast->next = NULL;
	last->next = first;
	*stackb = last;
	write(0, "rrb\n", 4);
}

void	rrr_move(t_list **stacka, t_list **stackb)
{
	rra_move(stacka);
	rrb_move(stackb);
	write(0, "rrr\n", 4);
}
