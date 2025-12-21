/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchioue <atchioue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:45:52 by atchioue          #+#    #+#             */
/*   Updated: 2025/12/16 16:45:52 by atchioue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorting_three(t_list **head)
{
	t_list	*top ;

	top = find_top(*head);
	if (*head == top)
		ra_move(head);
	else if ((*head)->next == top)
		rra_move(head);
	if ((*head)->nbr > (*head)->next->nbr)
		sa_move(head);
}
