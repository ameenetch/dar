/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down_rrx_moves_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:57:19 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/22 22:05:10 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cheker_bonus.h"

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
}

void	rrr_bonus(t_list **stack_a, t_list **stack_b)
{
	rra_move(stack_a);
	rrb_move(stack_b);
}
